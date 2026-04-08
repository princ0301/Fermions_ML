# Verilog Design Patterns for RTL

## Pipeline Register Pattern
```verilog
// Standard pipeline register with synchronous reset
always @(posedge clk or posedge rst) begin
    if (rst) begin
        stage_reg <= 0;
    end else if (enable) begin
        stage_reg <= stage_in;
    end
end
```

## Register File Pattern
```verilog
// 32x32 register file, x0 hardwired to 0
module reg_file (
    input clk,
    input we,
    input [4:0] rs1, rs2, rd,
    input [31:0] wdata,
    output [31:0] rdata1, rdata2
);
    reg [31:0] regs [0:31];
    assign rdata1 = (rs1 == 0) ? 32'b0 : regs[rs1];
    assign rdata2 = (rs2 == 0) ? 32'b0 : regs[rs2];
    always @(posedge clk) begin
        if (we && rd != 0)
            regs[rd] <= wdata;
    end
endmodule
```

## ALU Pattern
```verilog
module alu (
    input [31:0] a, b,
    input [3:0] op,
    output reg [31:0] result
);
    always @(*) begin
        case (op)
            4'b0000: result = a + b;           // ADD
            4'b0001: result = a - b;           // SUB
            4'b0010: result = a & b;           // AND
            4'b0011: result = a | b;           // OR
            4'b0100: result = a ^ b;           // XOR
            4'b0101: result = a << b[4:0];     // SLL
            4'b0110: result = a >> b[4:0];     // SRL
            4'b0111: result = $signed(a) >>> b[4:0]; // SRA
            4'b1000: result = ($signed(a) < $signed(b)) ? 1 : 0; // SLT
            4'b1001: result = (a < b) ? 1 : 0; // SLTU
            default: result = 32'b0;
        endcase
    end
endmodule
```

## FSM Pattern
```verilog
// Two-always FSM (recommended style)
// Always use non-blocking assignments in sequential block
reg [1:0] state, next_state;

// Sequential: state register
always @(posedge clk or posedge rst) begin
    if (rst) state <= IDLE;
    else     state <= next_state;
end

// Combinational: next state logic
always @(*) begin
    next_state = state;
    case (state)
        IDLE: if (start) next_state = FETCH;
        FETCH: next_state = DECODE;
        default: next_state = IDLE;
    endcase
end
```

## Synchronous Reset Convention
```verilog
// PREFERRED: synchronous reset
always @(posedge clk) begin
    if (rst) reg_out <= 0;
    else     reg_out <= reg_in;
end

// AVOID: asynchronous reset unless required
always @(posedge clk or posedge rst) begin
    if (rst) reg_out <= 0;
    else     reg_out <= reg_in;
end
```

## Branch Condition Logic
```verilog
// RISC-V branch conditions
always @(*) begin
    case (funct3)
        3'b000: branch_taken = (rs1_val == rs2_val);              // BEQ
        3'b001: branch_taken = (rs1_val != rs2_val);              // BNE
        3'b100: branch_taken = ($signed(rs1_val) < $signed(rs2_val)); // BLT
        3'b101: branch_taken = ($signed(rs1_val) >= $signed(rs2_val)); // BGE
        3'b110: branch_taken = (rs1_val < rs2_val);               // BLTU
        3'b111: branch_taken = (rs1_val >= rs2_val);              // BGEU
        default: branch_taken = 0;
    endcase
end
```

## Immediate Decode Pattern (RV32I)
```verilog
// RV32I immediate extraction
always @(*) begin
    case (opcode)
        7'b0010011: imm = {{20{inst[31]}}, inst[31:20]};          // I-type
        7'b0100011: imm = {{20{inst[31]}}, inst[31:25], inst[11:7]}; // S-type
        7'b1100011: imm = {{19{inst[31]}}, inst[31], inst[7],
                           inst[30:25], inst[11:8], 1'b0};        // B-type
        7'b1101111: imm = {{11{inst[31]}}, inst[31], inst[19:12],
                           inst[20], inst[30:21], 1'b0};          // J-type
        7'b0110111,
        7'b0010111: imm = {inst[31:12], 12'b0};                   // U-type
        default:    imm = 32'b0;
    endcase
end
```