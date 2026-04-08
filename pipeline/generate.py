import os
from pathlib import Path
from dotenv import load_dotenv
from langchain_groq import ChatGroq
from langchain_core.messages import HumanMessage, SystemMessage
from retrieve import retrieve, format_context

load_dotenv()

llm = ChatGroq(
    api_key=os.getenv("GROQ_API_KEY"),
    model_name="meta-llama/llama-4-scout-17b-16e-instruct",
    temperature=0.1,
    max_tokens=4096
)

SYSTEM_PROMPT = """You are an expert RTL (Register Transfer level) hardware design engineer
specializing in RISC-V processor implementation in Verilog.

Your job is to generate correct, synthesizable Verilog RTL code for RISC-V RV32I processor components.

Rules you MUST follow:
1. Always use non-blocking assignments (<=) in sequential always blocks
2. Always use blocking assignments (=) in combinational always blocks
3. Always use always @(*) for combinational logic
4. x0 register must ALWAYS read as zero and writes to x0 must be ignored
5. All modules must have clear port declarations with dorections and widths
6. Use synchronous reset unless told otherwise
7. Include comments explaining key logic
8. Do NOT use any SystemVerilog syntax - pure Verilog 2001 only
9. Shift amounts must be masked to 5 bits: b[4:0]
10. Signed comparisons must have $signed() cast

When given reference RTL and spec sontext, study it carefully before generating.
Output ONLY the Verilog code block, no explantion outside the code."""

COMPONENT_QUERIES = {
    "register_file": {
        "query": "RISC-V 32 register file x0 hardwired zero synchronous write read ports Verilog",
        "prompt": """Generate a Verilog module for a RISC-V RV32I register file with:
- 32 registers, each 32 bits wide
- x0 (register 0) hardwired to zero — reads always return 0, writes ignored
- Two asynchronous read ports (rs1, rs2)
- One synchronous write port (rd) on positive clock edge
- Synchronous reset to zero all registers
- Port list: clk, rst, we, rs1[4:0], rs2[4:0], rd[4:0], wdata[31:0], rdata1[31:0], rdata2[31:0]
Module name: reg_file"""
    },

    "alu": {
        "query": "RISC-V ALU arithmetic logic unit ADD SUB AND OR XOR SLL SRL SRA SLT SLTU Verilog",
        "prompt": """Generate a Verilog module for a RISC-V RV32I ALU supporting:
- ADD, SUB, AND, OR, XOR
- SLL (shift left logical), SRL (shift right logical), SRA (shift right arithmetic)
- SLT (set less than signed), SLTU (set less than unsigned)
- 4-bit alu_op control signal
- Port list: a[31:0], b[31:0], alu_op[3:0], result[31:0], zero (1 if result==0)
Module name: alu"""
    },

    "decoder": {
        "query": "RISC-V RV32I instruction decoder opcode funct3 funct7 immediate extract rs1 rs2 rd",
        "prompt": """Generate a Verilog module for a RISC-V RV32I instruction decoder that extracts:
- opcode [6:0], funct3 [2:0], funct7 [6:0]
- rs1 [4:0], rs2 [4:0], rd [4:0]
- 32-bit sign-extended immediate for I, S, B, U, J type instructions
- Control signals: reg_write, mem_read, mem_write, branch, jump, alu_src
- alu_op [3:0] based on opcode+funct3+funct7
- Port list: inst[31:0], and all outputs above
Module name: decoder"""
    },

    "pc": {
        "query": "RISC-V program counter fetch next PC branch jump sequential increment Verilog",
        "prompt": """Generate a Verilog module for a RISC-V program counter and instruction fetch unit:
- PC register, 32-bit, resets to 0
- Increments by 4 each cycle (sequential execution)
- Loads branch_target when branch_taken=1
- Loads jump_target when jump_taken=1  
- Stall input: when stall=1, PC does not update
- Output: current pc[31:0], next_pc[31:0]
- Port list: clk, rst, stall, branch_taken, branch_target[31:0], jump_taken, jump_target[31:0], pc[31:0]
Module name: program_counter"""
    },

    "branch_unit": {
        "query": "RISC-V branch unit BEQ BNE BLT BGE BLTU BGEU condition evaluation funct3",
        "prompt": """Generate a Verilog module for a RISC-V RV32I branch condition evaluator:
- Evaluates BEQ, BNE, BLT, BGE, BLTU, BGEU based on funct3
- Inputs: rs1_val[31:0], rs2_val[31:0], funct3[2:0], is_branch
- Output: branch_taken (1 if branch condition is true)
- BLT and BGE must use signed comparison with $signed()
- BLTU and BGEU use unsigned comparison
Module name: branch_unit"""
    },

    "load_store": {
        "query": "RISC-V load store unit LW LH LB SW SH SB byte enable sign extension memory",
        "prompt": """Generate a Verilog module for a RISC-V RV32I load/store unit:
- Supports LW, LH, LB (sign-extended), LHU, LBU (zero-extended) loads
- Supports SW, SH, SB stores with byte-enable signals
- Inputs: addr[31:0], wdata[31:0], funct3[2:0], mem_read, mem_write
- Outputs: rdata[31:0], byte_en[3:0], mem_addr[31:0], mem_wdata[31:0]
- Handle sign extension correctly based on funct3
Module name: load_store_unit"""
    },

    "pipeline_top": {
        "query": "RISC-V 5 stage pipeline fetch decode execute memory writeback hazard stall flush",
        "prompt": """Generate a top-level Verilog module for a 5-stage in-order RISC-V RV32I pipeline:
Stages: IF (Instruction Fetch) → ID (Decode) → EX (Execute) → MEM (Memory) → WB (Writeback)

Include:
- Pipeline registers between each stage (IF/ID, ID/EX, EX/MEM, MEM/WB)
- Hazard detection unit: stall on load-use hazard
- Forward unit: forward EX-EX and MEM-EX paths
- Branch resolution in EX stage with pipeline flush (zero IF/ID and ID/EX on taken branch)
- Connect reg_file, alu, decoder, program_counter, branch_unit, load_store_unit submodules

Port list: clk, rst, instr_mem_addr[31:0], instr_mem_data[31:0], 
           data_mem_addr[31:0], data_mem_wdata[31:0], data_mem_rdata[31:0],
           data_mem_we, data_mem_re
Module name: riscv_pipeline"""
    }
}

def generate_component(component_name: str, extra_context: str = "") -> str:
    if component_name not in COMPONENT_QUERIES:
        raise ValueError(f"unknown component: {component_name}")
    
    config = COMPONENT_QUERIES[component_name]

    print(f"Generating: {component_name}")

    print("\nRetrieving Context...")
    results = retrieve(config["query"], k=8)
    context = format_context(results)
    print(f"Retrieved {len(results)} chunks")

    user_prompt = f"""Here is relevant reference material from the RISC-V spec and existing RTL implementations:
{context}

{extra_context}

Now generate the following Verilog module:

{config['prompt']}

Output only the Verilog code. Start with `module` and end with `endmodule`. 
"""
    
    messages = [
        SystemMessage(content=SYSTEM_PROMPT),
        HumanMessage(content=user_prompt)
    ]
    response = llm.invoke(messages)
    raw_output = response.content

    verilog = extract_verilog(raw_output)

    out_path = Path(__file__).parent.parent / "generated_rtl" / f"{component_name}.v"
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(verilog, encoding="utf-8")
    print(f"Saved to: {out_path}")

    return verilog

def extract_verilog(text: str) -> str:
    import re
    match = re.search(r"```(?:verilog)?\n(.*?)```", text, re.DOTALL)
    if match:
        return match.group(1).strip()
    match = re.search(r"(module\s+\w+.*?endmodule)", text, re.DOTALL)
    if match:
        return match.group(1).strip()
    
    return text.strip()

if __name__ == "__main__":
    components = [
        "register_file",
        "alu",
        "decoder",
        "pc",
        "branch_unit",
        "load_store",
        "pipeline_top"
    ]
    for comp in components:
        verilog = generate_component(comp)
        print(f"\n--- Preview ({comp}) ---")
        print(verilog[:300])
        print("...")
