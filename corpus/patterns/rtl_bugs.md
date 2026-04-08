# Common RTL Bugs and Fixes

## Bug 1: Blocking vs Non-Blocking Assignments
```verilog
// WRONG: blocking assignment in sequential logic
always @(posedge clk) begin
    a = b;      // blocking — causes race conditions
    c = a;      // c gets NEW value of a, not registered
end

// CORRECT: non-blocking in sequential, blocking in combinational
always @(posedge clk) begin
    a <= b;     // non-blocking — scheduled at end of time step
    c <= a;     // c gets OLD value of a — correct pipeline behavior
end
```

## Bug 2: Incomplete Sensitivity List
```verilog
// WRONG: missing signals in sensitivity list
always @(a) begin
    out = a & b;   // b not in list — won't update when b changes
end

// CORRECT: use always @(*) for combinational
always @(*) begin
    out = a & b;
end
```

## Bug 3: x0 Register Not Hardwired to Zero
```verilog
// WRONG: allows writes to x0
always @(posedge clk) begin
    if (we) regs[rd] <= wdata;
end

// CORRECT: guard against x0 writes
always @(posedge clk) begin
    if (we && rd != 5'b0) regs[rd] <= wdata;
end
// AND on reads:
assign rdata = (rs == 5'b0) ? 32'b0 : regs[rs];
```

## Bug 4: Signed vs Unsigned Comparison
```verilog
// WRONG: unsigned comparison for SLT
assign slt = (a < b);   // treats as unsigned

// CORRECT: signed comparison
assign slt = ($signed(a) < $signed(b));
```

## Bug 5: Missing Pipeline Flush on Branch
```verilog
// WRONG: no flush — wrong instructions enter pipeline after branch
if (branch_taken) pc <= branch_target;

// CORRECT: flush fetch and decode stages
if (branch_taken) begin
    pc           <= branch_target;
    if_id_valid  <= 1'b0;   // kill instruction in IF/ID
    id_ex_valid  <= 1'b0;   // kill instruction in ID/EX
end
```

## Bug 6: Load-Use Hazard Not Handled
```verilog
// WRONG: no stall on load followed by dependent instruction
// If EX stage has a load and ID stage needs that register — data not ready

// CORRECT: detect and stall
wire load_use_hazard = (id_ex_memread) &&
                       ((id_ex_rd == if_id_rs1) || (id_ex_rd == if_id_rs2));
if (load_use_hazard) begin
    pc_write    <= 0;   // stall PC
    if_id_write <= 0;   // stall IF/ID
    id_ex_valid <= 0;   // insert bubble
end
```

## Bug 7: Shift Amount Truncation
```verilog
// WRONG: full 32-bit shift amount
assign result = a << b;   // Verilog may not truncate correctly

// CORRECT: mask shift amount to 5 bits for RV32I
assign result = a << b[4:0];
```

## Bug 8: Branch Target Calculation
```verilog
// WRONG: branch target from wrong PC
branch_target = pc + imm;   // if pc already incremented, this is off by 4

// CORRECT: branch from PC of branch instruction itself
branch_target = pc_of_branch_instr + imm;
```

## Bug 9: Memory Alignment for Loads/Stores
```verilog
// WRONG: ignoring byte offset for LH/LB
data_out = memory[addr];   // always reads full word

// CORRECT: handle byte/halfword with offset
case (funct3)
    3'b000: data_out = {{24{mem_data[7]}},  mem_data[7:0]};    // LB
    3'b001: data_out = {{16{mem_data[15]}}, mem_data[15:0]};   // LH
    3'b010: data_out = mem_data;                                // LW
    3'b100: data_out = {24'b0, mem_data[7:0]};                 // LBU
    3'b101: data_out = {16'b0, mem_data[15:0]};                // LHU
endcase
```

## Bug 10: Uninitialized Registers in Simulation
```verilog
// WRONG: registers start as X in simulation
reg [31:0] regs [0:31];

// CORRECT: initialize in an initial block for simulation
initial begin
    integer i;
    for (i = 0; i < 32; i = i+1)
        regs[i] = 32'b0;
end
```