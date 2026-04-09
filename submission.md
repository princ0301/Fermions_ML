# RAG for RISC-V RTL — Submission

| Field        | Details                                              |
|--------------|------------------------------------------------------|
| **Name**     | Prince Kumar                                         |
| **Email**    | princeku07190@gmail.com                              |
| **Phone**    | +91 6204313778                                       |
| **Country**  | India                                                |
| **Date**     | 2026-04-09                                           |
| **LinkedIn** | https://www.linkedin.com/in/prince-kumar-66ba45293/  |
| **GitHub**   | https://github.com/princ0301/Fermions_ML             |

---

## A. Corpus & Knowledge Base

### Sources Used

**1. RISC-V Unprivileged ISA Specification (PDF)**
- Downloaded from the official RISC-V GitHub releases: `riscv-spec-20191213.pdf`
- Chunked by page groups (3 pages per chunk, 1500 tokens, 200 overlap) using LangChain's `RecursiveCharacterTextSplitter`
- Provides ground truth for instruction encodings, immediate formats, opcode tables, and register conventions

**2. PicoRV32 Reference RTL (`picorv32.v`)**
- Downloaded from [YosysHQ/picorv32](https://github.com/YosysHQ/picorv32)
- A well-known, correct, single-file RV32I implementation
- Chunked at **Verilog module boundaries** using a custom regex splitter: `re.split(r'(?=\bmodule\b)', text)`
- This is semantically correct — a module boundary in Verilog is analogous to a class boundary in software, not a paragraph break

**3. Verilog Design Patterns (`verilog_patterns.md`)**
- Manually authored reference document
- Contains: pipeline register template, register file pattern, ALU pattern, FSM template, branch condition logic, immediate decode patterns for all RV32I instruction types
- Chunked by paragraph (800 tokens, 100 overlap)

**4. RTL Bug Reference (`rtl_bugs.md`)**
- Manually authored document of 10 common RTL bugs with correct/incorrect examples
- Covers: blocking vs non-blocking assignments, incomplete sensitivity lists, x0 not hardwired, signed/unsigned mismatches, missing pipeline flush, load-use hazard, shift amount truncation, branch target calculation, memory alignment, uninitialized registers
- Chunked by paragraph (800 tokens, 100 overlap)

### Chunking Strategy

| Source | Splitter | Chunk Size | Overlap | Rationale |
|--------|----------|------------|---------|-----------|
| RISC-V Spec PDF | RecursiveCharacterTextSplitter | 1500 tokens | 200 | Preserves page-level context |
| PicoRV32 RTL | Custom module-boundary splitter | Variable | 0 | Module = semantic unit |
| Verilog Patterns | RecursiveCharacterTextSplitter | 800 tokens | 100 | Pattern fits in one chunk |
| RTL Bugs | RecursiveCharacterTextSplitter | 800 tokens | 100 | Bug+fix pair fits together |

**Total chunks ingested: 480**

### Embedding Model

- **Model:** `sentence-transformers/all-MiniLM-L6-v2` via HuggingFace
- **Rationale:** Fast, local (no API cost), good semantic similarity for mixed code+prose content. Runs on CPU without GPU requirement.
- **Vector Store:** ChromaDB (local persistent directory `vectorstore/`)

### Retrieval Approach

- **Strategy:** Dense vector similarity search (cosine)
- **Top-k:** 8 chunks per query
- **Why k=8:** Balances context richness (more relevant chunks) against prompt length (LLM context window). Tested k=4 and k=12 — k=8 gave best RTL quality.
- No re-ranking applied in this pipeline (future improvement: cross-encoder reranker)

---

## B. Pipeline Design

### Architecture

```
Query (component description)
        │
        ▼
┌─────────────────┐
│  Retriever      │  sentence-transformers/all-MiniLM-L6-v2
│  ChromaDB       │  Top-8 chunks
└────────┬────────┘
         │  Retrieved context (spec + RTL + patterns + bugs)
         ▼
┌─────────────────┐
│  Prompt Builder │  System prompt + context + component spec
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  Groq LLM       │  llama-3.1-70b-versatile
│  (ChatGroq)     │  temperature=0.1, max_tokens=4096
└────────┬────────┘
         │  Raw LLM output
         ▼
┌─────────────────┐
│  Post-processor │  Regex extract module...endmodule
└────────┬────────┘
         │
         ▼
   generated_rtl/<component>.v
```

### Key Design Decisions

**Temperature = 0.1:** RTL generation is deterministic by nature. High temperature introduces random variation that breaks syntax. Low temperature keeps the model focused on the retrieved context.

**Component-by-component generation:** Rather than prompting for a full processor at once, we generate each component independently. This allows targeted retrieval (the register file query retrieves register-relevant chunks, not branch-relevant ones), easier debugging, and incremental verification.

**System prompt with hard rules:** The system prompt enforces 10 RTL rules including non-blocking assignments in sequential blocks, x0 hardwired to zero, Verilog 2001 only (no SystemVerilog), and signed comparisons using `$signed()`. Without these constraints, the LLM defaulted to SystemVerilog syntax incompatible with Verilator.

**Hybrid corpus (spec + RTL + patterns + bugs):** Pure spec retrieval gives semantic correctness but poor code style. Pure RTL retrieval gives style but misses edge cases. The combination grounds the generation in both correctness and implementation patterns.

### Tools and Models

| Component | Tool/Model |
|-----------|------------|
| LLM | `llama-3.1-70b-versatile` via Groq API |
| LangChain integration | `langchain-groq` / `ChatGroq` |
| Embeddings | `sentence-transformers/all-MiniLM-L6-v2` |
| Vector store | ChromaDB (local) |
| RAG framework | LangChain |
| Simulation | Verilator 5.022 |
| OS | Ubuntu 24 (WSL2 on Windows 11) |

---

## C. Generated RTL

### Final Generated Verilog

All generated RTL is available at: **https://github.com/princ0301/Fermions_ML/tree/main/generated_rtl**

Components generated:
- `register_file.v` — 32×32 register file, x0 hardwired
- `alu.v` — Full RV32I ALU with 10 operations
- `decoder.v` — Instruction decoder (manually corrected opcodes)
- `pc.v` — Program counter with stall/branch/jump
- `branch_unit.v` — Branch condition evaluator
- `load_store.v` — Load/store unit (manually corrected)
- `pipeline_top.v` — Self-contained 5-stage pipeline (manually corrected)

### Example RAG Traces

#### Trace 1: Register File Generation

**Query sent to retriever:**
```
RISC-V 32 register file x0 hardwired zero synchronous write read ports Verilog
```

**Top retrieved chunks (sample):**
```
--- Chunk 1 (source: verilog_patterns.md, score: 0.312) ---
// 32x32 register file, x0 hardwired to 0
module reg_file (
    input clk, input we, input [4:0] rs1, rs2, rd,
    input [31:0] wdata, output [31:0] rdata1, rdata2
);
    reg [31:0] regs [0:31];
    assign rdata1 = (rs1 == 0) ? 32'b0 : regs[rs1];
    ...

--- Chunk 3 (source: picorv32.v, score: 0.445) ---
module picorv32_regs (...)
    reg [31:0] regs [1:31];  // Note: starts at 1, x0 handled separately
    ...

--- Chunk 5 (source: rtl_bugs.md, score: 0.521) ---
// Bug 3: x0 Register Not Hardwired to Zero
// CORRECT: guard against x0 writes
always @(posedge clk) begin
    if (we && rd != 5'b0) regs[rd] <= wdata;
end
assign rdata = (rs == 5'b0) ? 32'b0 : regs[rs];
```

**Generated output (passing 6/6 tests):**
```verilog
module reg_file (
    input clk, input rst, input we,
    input [4:0] rs1, rs2, rd,
    input [31:0] wdata,
    output [31:0] rdata1, rdata2
);
    reg [31:0] regs [0:31];
    assign rdata1 = (rs1 == 5'b0) ? 32'b0 : regs[rs1];
    assign rdata2 = (rs2 == 5'b0) ? 32'b0 : regs[rs2];
    always @(posedge clk) begin
        if (rst) begin: reset_loop
            integer i;
            for (i = 0; i < 32; i = i+1) regs[i] <= 32'b0;
        end else if (we && rd != 5'b0)
            regs[rd] <= wdata;
    end
endmodule
```
**Iterations:** 1 (first generation passed all tests)

---

#### Trace 2: Decoder Generation (Failure Case)

**Query sent to retriever:**
```
RISC-V RV32I instruction decoder opcode funct3 funct7 immediate extract rs1 rs2 rd
```

**Generated output (first attempt — wrong opcodes):**
```verilog
// LLM hallucinated incorrect opcodes:
assign imm = opcode == 7'b0010111 ? imm_u : // LUI  ← WRONG (should be 0110111)
             opcode == 7'b0110111 ? imm_i : // AUIPC ← WRONG (should be 0010111)
             opcode == 7'b1100111 ? imm_i : // ADDI  ← WRONG (should be 0010011)
             opcode == 7'b1101111 ? imm_b : // BEQ   ← WRONG (should be 1100011)
```

**Root cause:** The LLM confused opcode values across instruction types. The RISC-V opcode space is dense and the values differ by only 1-2 bits — the model hallucinated plausible-looking but incorrect values. The retrieved spec chunks contained the correct table but the model failed to extract the exact binary values reliably.

**Fix:** Manual correction of all opcode `localparam` values to match the RV32I spec exactly. See `generated_rtl/decoder.v` for corrected version.

**Iterations:** 2 (1 generation + 1 manual correction)

---

#### Trace 3: Pipeline Top Generation (Failure Case)

**Query sent to retriever:**
```
RISC-V 5 stage pipeline fetch decode execute memory writeback hazard stall flush
```

**Generated output (first attempt — illegal Verilog):**
```verilog
// LLM accessed internal signals of submodules — illegal in Verilog:
always @(posedge clk) begin
    if (rst) begin
        pc_u.pc <= 32'h00000000;  // ILLEGAL: cannot drive submodule internals
    end
end
// Also: all submodule ports were unconnected
reg_file_u(.clk(clk), .rst(rst));  // missing all data/control ports
```

**Fix:** Complete rewrite as a self-contained pipeline without submodule instantiation. The final `pipeline_top.v` inlines all pipeline logic directly, which is cleaner and avoids the port-connection complexity the LLM struggled with.

**Iterations:** 3 (1 LLM generation + 1 attempted fix + 1 manual rewrite)

---

## D. Simulation Results

### Verilator Setup

- **Verilator version:** 5.022 (built from source — apt package 5.020 had GCC 13 incompatibility)
- **Compile flags:** `-std=c++20 -O2`
- **Trace:** VCD waveform output for GTKWave visualization

### Component-Level Test Results

| Component | Tests | Passed | Failed | Notes |
|-----------|-------|--------|--------|-------|
| ALU | 11 | 11 | 0 | All operations correct including signed comparisons |
| Register File | 6 | 6 | 0 | x0 hardwiring, dual read ports, write enable |
| Branch Unit | 13 | 12 | 1 | `is_branch` input declared but unused in logic |
| Program Counter | 9 | 9 | 0 | Stall, branch, jump, sequential all correct |
| Decoder | 31 | 28 | 3 | rd/rs1 field offset in test vectors |
| Load/Store | 10 | 7 | 3 | byte_en not driven on load operations |
| **Total** | **80** | **75** | **5** | **93.75% pass rate** |

### Pipeline Integration Test

Executed the following instruction sequence through the full 5-stage pipeline:

```
ADDI x1, x0, 5     # x1 = 5
ADDI x2, x0, 10    # x2 = 10
ADD  x3, x1, x2    # x3 = 15  (forwarding required)
SW   x3, 0(x0)     # mem[0] = 15
LW   x4, 0(x0)     # x4 = 15  (load from memory)
```

**Result:**
```
Cycle 15 | PC=0x3c | [WRITE 0x0=0xf]   ✅  SW executed correctly
Cycle 16 | PC=0x40 | [READ  0x0=0xf]   ✅  LW executed correctly
Final dmem[0] = 0xf (Expected: 0xf)    ✅  PASS
```

The pipeline correctly computed 5+10=15 and stored/loaded it through data memory with forwarding active.

### ISA Test Suite

Due to the complexity of setting up the full `riscv-tests` infrastructure (requires RISC-V GCC cross-compiler, linker scripts, and ELF loading), full ISA test suite integration was not completed within the submission timeline. The component-level and pipeline integration tests demonstrate functional correctness for the core RV32I instruction subset (arithmetic, loads, stores).

---

## E. Failure Analysis

### Failure 1: Decoder — Wrong Opcodes (Major)

**What failed:** The LLM generated entirely incorrect opcode values for all instruction types. For example, LUI was assigned `7'b0010111` (correct is `7'b0110111`), AUIPC got LUI's opcode, and branch/load/store opcodes were invented.

**Why it failed:** The RISC-V opcode space is dense — most opcodes differ by 1-2 bits. The LLM learned the opcode *names* and their *general purpose* from training data, but could not reliably recall exact binary values. The retrieved spec chunks contained correct opcode tables, but the model failed to extract and apply them precisely.

**How fixed:** Manual correction of all opcode localparams against the RV32I spec table. This is a fundamental limitation of LLM-based RTL generation for spec-derived constants.

**Retrieval improvement that could help:** Chunking the spec opcode table as a single atomic chunk and storing it as a high-priority document with explicit metadata tagging.

---

### Failure 2: Pipeline Top — Illegal Submodule Access (Major)

**What failed:** The LLM generated code that directly drove internal registers of instantiated submodules (`pc_u.pc <= value`) and left all submodule ports unconnected.

**Why it failed:** The LLM conflated the concept of "connecting modules" with "accessing module internals." This is a fundamental Verilog rule (ports are the only legal interface) that the model violated. The prompt asked to "connect submodules" but the model had no prior retrieved example of correct module instantiation with full port mapping.

**How fixed:** Complete manual rewrite as a self-contained pipeline. The fix also improved design quality — inlining avoids the port-connection overhead entirely.

**Retrieval improvement:** Adding a corpus entry with a complete, correct example of a multi-module Verilog design with explicit port connections.

---

### Failure 3: Branch Unit — Unused Port (Minor)

**What failed:** `is_branch` was declared as an input but never referenced in the combinational logic. The branch condition fired regardless of whether the instruction was actually a branch.

**Why it failed:** The prompt specified `is_branch` as a port but didn't explicitly say "gate all output on is_branch." The LLM added it to the port list to satisfy the spec but forgot to use it.

**How fixed:** Not fixed (kept as documented failure). Fix would be adding `if (!is_branch) branch_taken = 0;` as a guard.

---

### Failure 4: Load/Store — byte_en Not Driven on Reads (Minor)

**What failed:** `byte_en` is only asserted when `mem_write=1`. For loads, `byte_en` stays 0, meaning the memory interface can't know which bytes to read.

**Why it failed:** The LLM modeled `byte_en` as a "store enable" signal rather than a general "active byte" signal used by both loads and stores.

**How fixed:** Not fixed (kept as documented failure). Fix: drive `byte_en` based on `funct3` regardless of `mem_read`/`mem_write`.

---

### Failure 5: Immediate Decode Width Mismatch (Minor)

**What failed:** The original decoder had bit-width mismatches in immediate construction — e.g., `{{20{inst[31]}}, inst[30:20]}` produces 31 bits not 32 (inst[31] counted twice).

**Why it failed:** Bit arithmetic errors in concatenation — the LLM miscounted the sign-extension replication factor.

**How fixed:** Corrected to `{{20{inst[31]}}, inst[31:20]}` which correctly produces 20+12=32 bits.

---

## F. Reflection

### What was the hardest part?

**The gap between syntactic correctness and semantic correctness.** The LLM was remarkably good at generating Verilog that *looks* right — correct module structure, port declarations, always blocks, case statements. But it consistently failed at *semantic* correctness: wrong opcode values, unused ports, illegal signal access across module boundaries.

This is the core challenge described in the Fermions article — LLMs optimize for pattern matching, not for hardware semantics. A wrong opcode value is invisible to a syntax checker but causes complete functional failure.

The second hardest part was the Verilator toolchain setup on Windows (WSL2 + GCC 13 incompatibility with Verilator 5.020 required building from source).

### What would I do differently with more time?

**1. Better spec chunking:** The RISC-V spec opcode table should be a single, atomic, high-priority chunk with metadata like `{"type": "opcode_table", "priority": "high"}`. The current chunking by page groups splits tables across chunks, losing structure.

**2. Re-ranking:** Add a cross-encoder reranker (e.g., `cross-encoder/ms-marco-MiniLM-L-6-v2`) between retrieval and generation. This would filter out low-relevance chunks and improve signal-to-noise in the context.

**3. Iterative verification loop:** Build a feedback loop where Verilator errors are fed back to the LLM for self-correction. Currently generation is one-shot — with an auto-repair loop, failures like the opcode errors could be caught and corrected automatically.

**4. Hardware-specific embedding model:** `all-MiniLM-L6-v2` is a general-purpose model. A code-specific model like `jinaai/jina-embeddings-v2-base-code` would likely retrieve more relevant Verilog chunks for hardware queries.

**5. Full ISA test suite:** Set up the `riscv-tests` infrastructure with a proper ELF loader in the Verilator testbench to run all 47 `rv32ui-p-*` tests.

### What does this tell us about the limits of RAG for hardware generation?

RAG helps significantly with *style* and *structure* — the generated modules had correct port declarations, proper always block usage, and good commenting because the retrieved PicoRV32 examples demonstrated these patterns. But RAG cannot fix the fundamental problem: **LLMs don't reason about bit-level hardware semantics the way they reason about high-level software logic.**

Three specific limits emerged:

**Spec constants are unreliable.** The LLM hallucinated opcode values despite having the correct spec table in its retrieved context. For hardware, exact binary values matter — a 1-bit error in an opcode breaks all instructions of that type. RAG can retrieve the right document but cannot guarantee the model extracts exact numeric values correctly.

**Port connectivity is fragile.** The LLM consistently struggled with multi-module integration — connecting ports correctly, not accessing module internals, propagating signals through pipeline registers. This requires understanding of Verilog's structural semantics that goes beyond pattern matching.

**Hazard logic requires reasoning, not retrieval.** The load-use hazard detector and forwarding unit require understanding of *why* certain conditions cause incorrect behavior — not just what the correct code looks like. RAG can retrieve examples of hazard logic, but the model must reason about the specific pipeline's timing to instantiate it correctly. This is where LLMs fall shortest.

The conclusion: RAG is a useful scaffold for hardware RTL generation, but current LLMs require significant human verification and correction for production-quality RTL. The value is in accelerating the first draft — reducing time-to-simulatable-code — not in producing verified, correct RTL autonomously.