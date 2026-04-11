# RAG-Driven RTL Generation for a Simple In-Order RISC-V Processor

## Overview

This project builds a **Retrieval-Augmented Generation (RAG) pipeline** that generates synthesizable Verilog RTL for a 5-stage in-order RISC-V RV32I processor. Each generated component is verified using Verilator simulation with custom C++ testbenches.

### Results at a Glance

| Component | Tests | Passed |
|-----------|-------|--------|
| ALU | 11 | 11 |
| Register File | 6 | 6 |
| Program Counter | 9 | 9 |
| Branch Unit | 13 | 12 |
| Decoder | 31 | 28 |  
| Load/Store Unit | 10 | 7 |  
| **Pipeline Integration** | — | — |  
| **Total** | **80** | **75** | **93.75%** |

---

## Repository Structure

```
Fermions_ML/
├── corpus/
│   ├── spec/                  # RISC-V Unprivileged ISA spec PDF
│   ├── rtl_ref/               # PicoRV32 reference RTL
│   └── patterns/              # Verilog patterns + RTL bug reference + RV32I opcode table
├── pipeline/
│   ├── ingest.py              # Corpus chunking, embedding, ChromaDB ingestion
│   ├── retrieve.py            # Two-stage retrieval: embedding + cross-encoder reranking
│   └── generate.py            # Groq LLM generation with structured prompts
├── generated_rtl/
│   ├── alu.v                  # ALU — 10 operations
│   ├── register_file.v        # 32x32 register file, x0 hardwired
│   ├── decoder.v              # RV32I instruction decoder
│   ├── pc.v                   # Program counter with stall/branch/jump
│   ├── branch_unit.v          # Branch condition evaluator
│   ├── load_store.v           # Load/store unit with byte enables
│   └── pipeline_top.v        # 5-stage pipeline integration
├── sim/
│   ├── tb_alu.cpp             # ALU testbench
│   ├── tb_reg_file.cpp        # Register file testbench
│   ├── tb_branch_unit.cpp     # Branch unit testbench
│   ├── tb_pc.cpp              # Program counter testbench
│   ├── tb_decoder.cpp         # Decoder testbench
│   ├── tb_load_store.cpp      # Load/store testbench
│   └── tb_pipeline.cpp        # Full pipeline integration testbench
├── vectorstore/               # ChromaDB persistent vector store
├── submission_prince_kumar.md # Full submission document
├── requirements.txt
└── README.md
```

---

## RAG Pipeline

### Architecture

```
Query (component description)
        │
        ▼
┌─────────────────┐
│  ChromaDB       │  sentence-transformers/all-MiniLM-L6-v2
│  Retriever      │  Top-30 candidates
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  Filter + Dedup │  Blacklist RVC/RV64 chunks
│                 │  Deduplicate by content hash
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  Cross-Encoder  │  cross-encoder/ms-marco-MiniLM-L-6-v2
│  Re-ranker      │  → Top-8 by rerank score
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  Groq LLM       │  llama-4
│  (ChatGroq)     │  temperature=0.1
└────────┬────────┘
         │
         ▼
   generated_rtl/<component>.v
```

### Stack

| Component | Tool |
|-----------|------|
| LLM | `llama-4` via Groq API |
| Embeddings | `sentence-transformers/all-MiniLM-L6-v2` |
| Re-ranker | `cross-encoder/ms-marco-MiniLM-L-6-v2` |
| Vector Store | ChromaDB (local) |
| RAG Framework | LangChain |
| Simulation | Verilator 5.022 |

---

## Setup & Usage

### Prerequisites

- Python 3.10+
- WSL2 (Ubuntu 24) for Verilator simulation
- Groq API key (free at [console.groq.com](https://console.groq.com))

### Installation

```bash
git clone https://github.com/princ0301/Fermions_ML
cd Fermions_ML
pip install -r requirements.txt
```

Create a `.env` file:
```
GROQ_API_KEY=your_groq_api_key_here
```

### Step 1 — Ingest Corpus

```bash
python pipeline/ingest.py
```

Chunks and embeds all corpus files into ChromaDB. Output: `vectorstore/` directory.

### Step 2 — Generate RTL

```bash
python pipeline/generate.py
```

Generates all 7 Verilog components using RAG + Groq LLM. Output: `generated_rtl/*.v`

### Step 3 — Simulate (WSL2)

Install Verilator from source (required — apt version has GCC 13 incompatibility):

```bash
sudo apt install -y git autoconf flex bison libfl2 libfl-dev
git clone https://github.com/verilator/verilator
cd verilator && git checkout v5.022
autoconf && ./configure && make -j$(nproc) && sudo make install
export PATH=/usr/local/bin:$PATH
```

Run ALU testbench:

```bash
cd /path/to/Fermions_ML

verilator --cc --trace -Wno-fatal --top-module alu \
    generated_rtl/alu.v --Mdir sim/obj_alu

make -C sim/obj_alu -f Valu.mk CXX=g++ CXXFLAGS="-std=c++20 -O2"

cd sim
g++ tb_alu.cpp obj_alu/Valu__ALL.a obj_alu/libverilated.a \
    -I/usr/local/share/verilator/include \
    -I/usr/local/share/verilator/include/vltstd \
    -Iobj_alu -std=c++20 -o sim_alu.out && ./sim_alu.out
```

Run pipeline integration test:

```bash
verilator --cc --trace -Wno-fatal --top-module riscv_pipeline \
    generated_rtl/*.v --Mdir sim/obj_pipeline

make -C sim/obj_pipeline -f Vriscv_pipeline.mk CXX=g++ CXXFLAGS="-std=c++20 -O2"

cd sim
g++ tb_pipeline.cpp obj_pipeline/Vriscv_pipeline__ALL.a \
    obj_pipeline/libverilated.a \
    -I/usr/local/share/verilator/include \
    -Iobj_pipeline -std=c++20 -o sim_pipeline.out && ./sim_pipeline.out
```

Expected output:
```
Cycle 15 | PC=0x3c | [WRITE 0x0=0xf]
Cycle 16 | PC=0x40 | [READ  0x0=0xf]
Final dmem[0] = 0xf (Expected: 0xf)
```

---

## Corpus

| Source | Purpose | Chunking |
|--------|---------|----------|
| `riscv-spec-20191213.pdf` | Ground truth encodings | Page-level, 1500 tokens |
| `picorv32.v` | Correct RTL reference | Module boundaries |
| `verilog_patterns.md` | Design patterns | Paragraph, 800 tokens |
| `rtl_bugs.md` | Common mistakes + fixes | Paragraph, 800 tokens |
| `rv32i_opcodes.md` | Hand-crafted opcode table | Single chunk |

**Total: 480 chunks**

---

## Key Findings

### What RAG does well
- **RTL style and structure** — correct always block usage, port declarations, non-blocking assignments — learned from PicoRV32 reference
- **Simple self-contained modules** — ALU (11/11) and Register File (6/6) generated perfectly on first attempt
- **Re-ranking improves precision** — cross-encoder separated relevant spec chunks (score 5.559) from irrelevant RVC chunks (score -0.120) that embedding similarity could not distinguish

### Where RAG fails
- **Spec constants** — LLM hallucinated wrong opcode values despite correct spec in context. Exact binary values are unreliable.
- **Multi-module integration** — LLM accessed submodule internals illegally (`pc_u.pc <= value`) — a fundamental Verilog rule it violated
- **Unused ports** — `is_branch` declared but never used in branch unit logic

### Re-ranking Impact
Before re-ranking: RVC (compressed instruction) chunks appeared in top-8 for opcode queries despite being irrelevant.  
After re-ranking + filtering: Correct RV32I opcode table ranked first at score 5.559, irrelevant chunks scored below 0 and excluded.
 