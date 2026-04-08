module decoder(
    input  wire [31:0] inst,
    output wire [6:0]  opcode,
    output wire [2:0]  funct3,
    output wire [6:0]  funct7,
    output wire [4:0]  rs1,
    output wire [4:0]  rs2,
    output wire [4:0]  rd,
    output wire [31:0] imm,
    output wire        reg_write,
    output wire        mem_read,
    output wire        mem_write,
    output wire        branch,
    output wire        jump,
    output wire        alu_src,
    output wire [3:0]  alu_op
);

    assign opcode = inst[6:0];
    assign funct3 = inst[14:12];
    assign funct7 = inst[31:25];
    assign rs1    = inst[19:15];
    assign rs2    = inst[24:20];
    assign rd     = inst[11:7];

    localparam OP_RTYPE  = 7'b0110011;
    localparam OP_ITYPE  = 7'b0010011;
    localparam OP_LOAD   = 7'b0000011;
    localparam OP_STORE  = 7'b0100011;
    localparam OP_BRANCH = 7'b1100011;
    localparam OP_JAL    = 7'b1101111;
    localparam OP_JALR   = 7'b1100111;
    localparam OP_LUI    = 7'b0110111;
    localparam OP_AUIPC  = 7'b0010111;

    wire [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;

    assign imm_i = {{20{inst[31]}}, inst[31:20]};
    assign imm_s = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    assign imm_b = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
    assign imm_u = {inst[31:12], 12'b0};
    assign imm_j = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};

    assign imm = (opcode == OP_LOAD  || opcode == OP_ITYPE || opcode == OP_JALR) ? imm_i :
                 (opcode == OP_STORE)  ? imm_s :
                 (opcode == OP_BRANCH) ? imm_b :
                 (opcode == OP_LUI    || opcode == OP_AUIPC) ? imm_u :
                 (opcode == OP_JAL)    ? imm_j :
                 32'b0;

    assign reg_write = (opcode == OP_RTYPE  ||
                        opcode == OP_ITYPE  ||
                        opcode == OP_LOAD   ||
                        opcode == OP_JAL    ||
                        opcode == OP_JALR   ||
                        opcode == OP_LUI    ||
                        opcode == OP_AUIPC);

    assign mem_read  = (opcode == OP_LOAD);
    assign mem_write = (opcode == OP_STORE);
    assign branch    = (opcode == OP_BRANCH);
    assign jump      = (opcode == OP_JAL || opcode == OP_JALR);
    assign alu_src   = (opcode == OP_ITYPE  ||
                        opcode == OP_LOAD   ||
                        opcode == OP_STORE  ||
                        opcode == OP_JALR   ||
                        opcode == OP_LUI    ||
                        opcode == OP_AUIPC);

    wire sub_op = (opcode == OP_RTYPE) && (funct7[5] == 1'b1);

    assign alu_op =
        (opcode == OP_BRANCH) ?
            (funct3 == 3'b000 ? 4'b0001 :
             funct3 == 3'b001 ? 4'b0001 :
             funct3 == 3'b100 ? 4'b1000 :
             funct3 == 3'b101 ? 4'b1000 :
             funct3 == 3'b110 ? 4'b1001 :
             funct3 == 3'b111 ? 4'b1001 :
             4'b0000) :
        (opcode == OP_RTYPE || opcode == OP_ITYPE) ?
            (funct3 == 3'b000 ? (sub_op ? 4'b0001 : 4'b0000) :
             funct3 == 3'b001 ? 4'b0101 :
             funct3 == 3'b010 ? 4'b1000 :
             funct3 == 3'b011 ? 4'b1001 :
             funct3 == 3'b100 ? 4'b0100 :
             funct3 == 3'b101 ? (funct7[5] ? 4'b0111 : 4'b0110) :
             funct3 == 3'b110 ? 4'b0011 :
             funct3 == 3'b111 ? 4'b0010 :
             4'b0000) :
        4'b0000;

endmodule
