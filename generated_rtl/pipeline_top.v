module riscv_pipeline (
    input clk,
    input rst,
 
    output [31:0] instr_mem_addr,
    input  [31:0] instr_mem_data,
 
    output reg        data_mem_we,
    output reg        data_mem_re,
    output reg [31:0] data_mem_addr,
    output reg [31:0] data_mem_wdata,
    input      [31:0] data_mem_rdata
);
 
    reg [31:0] pc;
    assign instr_mem_addr = pc;

    always @(posedge clk) begin
        if (rst) pc <= 0;
        else     pc <= pc + 4;
    end
 
    reg [31:0] if_id_instr;
    always @(posedge clk) begin
        if (rst) if_id_instr <= 32'h00000013;
        else     if_id_instr <= instr_mem_data;
    end
 
    wire [6:0] opcode = if_id_instr[6:0];
    wire [2:0] funct3 = if_id_instr[14:12];
    wire [4:0] rs1    = if_id_instr[19:15];
    wire [4:0] rs2    = if_id_instr[24:20];
    wire [4:0] rd     = if_id_instr[11:7];

    wire [31:0] imm_i = {{20{if_id_instr[31]}}, if_id_instr[31:20]};
    wire [31:0] imm_s = {{20{if_id_instr[31]}}, if_id_instr[31:25], if_id_instr[11:7]};

    reg [31:0] regfile [0:31];
    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1) regfile[i] = 0;
    end
 
    reg [31:0] id_ex_rs1_data, id_ex_rs2_data, id_ex_imm;
    reg [4:0]  id_ex_rd, id_ex_rs1, id_ex_rs2;
    reg [6:0]  id_ex_opcode;

    always @(posedge clk) begin
        if (rst) begin
            id_ex_opcode   <= 7'h13;
            id_ex_rd       <= 0;
            id_ex_rs1      <= 0;
            id_ex_rs2      <= 0;
            id_ex_rs1_data <= 0;
            id_ex_rs2_data <= 0;
            id_ex_imm      <= 0;
        end else begin
            id_ex_opcode   <= opcode;
            id_ex_rd       <= rd;
            id_ex_rs1      <= rs1;
            id_ex_rs2      <= rs2;
            id_ex_rs1_data <= regfile[rs1];
            id_ex_rs2_data <= regfile[rs2];
            id_ex_imm      <= (opcode == 7'b0100011) ? imm_s : imm_i;
        end
    end
 
    reg [31:0] ex_mem_result;
    reg [31:0] ex_mem_wdata;
    reg [4:0]  ex_mem_rd;
    reg        ex_mem_reg_write;
    reg        ex_mem_mem_re, ex_mem_mem_we;
 
    wire [31:0] mem_wb_final_result;  

    wire [31:0] fwd_a = (ex_mem_reg_write && ex_mem_rd == id_ex_rs1 && ex_mem_rd != 0) ? ex_mem_result :
                         (mem_wb_reg_write && mem_wb_rd == id_ex_rs1 && mem_wb_rd != 0) ? mem_wb_final_result : 
                         id_ex_rs1_data;

    wire [31:0] fwd_b = (ex_mem_reg_write && ex_mem_rd == id_ex_rs2 && ex_mem_rd != 0) ? ex_mem_result :
                         (mem_wb_reg_write && mem_wb_rd == id_ex_rs2 && mem_wb_rd != 0) ? mem_wb_final_result : 
                         id_ex_rs2_data;

    always @(posedge clk) begin
        if (rst) begin
            ex_mem_reg_write <= 0;
            ex_mem_mem_re    <= 0;
            ex_mem_mem_we    <= 0;
            ex_mem_result    <= 0;
            ex_mem_wdata     <= 0;
            ex_mem_rd        <= 0;
        end else begin
            ex_mem_rd        <= id_ex_rd;
            ex_mem_mem_we    <= (id_ex_opcode == 7'b0100011);
            ex_mem_mem_re    <= (id_ex_opcode == 7'b0000011);
            ex_mem_reg_write <= (id_ex_opcode == 7'b0010011 || id_ex_opcode == 7'b0110011 || id_ex_opcode == 7'b0000011);
            
            case (id_ex_opcode)
                7'b0010011: ex_mem_result <= fwd_a + id_ex_imm;
                7'b0110011: ex_mem_result <= fwd_a + fwd_b;
                7'b0100011: begin 
                    ex_mem_result <= fwd_a + id_ex_imm;
                    ex_mem_wdata  <= fwd_b;
                end
                7'b0000011: ex_mem_result <= fwd_a + id_ex_imm;
                default:    ex_mem_result <= 0;
            endcase
        end
    end
 
    reg [31:0] mem_wb_result;
    reg [31:0] mem_wb_rdata;
    reg [4:0]  mem_wb_rd;
    reg        mem_wb_reg_write;
    reg        mem_wb_mem_to_reg;

    always @(*) begin
        data_mem_we    = ex_mem_mem_we;
        data_mem_re    = ex_mem_mem_re;
        data_mem_addr  = ex_mem_result;
        data_mem_wdata = ex_mem_wdata;
    end

    always @(posedge clk) begin
        if (rst) begin
            mem_wb_reg_write <= 0;
            mem_wb_rd         <= 0;
            mem_wb_result     <= 0;
            mem_wb_rdata      <= 0;
            mem_wb_mem_to_reg <= 0;
        end else begin
            mem_wb_rd         <= ex_mem_rd;
            mem_wb_reg_write  <= ex_mem_reg_write;
            mem_wb_result     <= ex_mem_result;
            mem_wb_rdata      <= data_mem_rdata;
            mem_wb_mem_to_reg <= ex_mem_mem_re;
        end
    end
 
    assign mem_wb_final_result = mem_wb_mem_to_reg ? mem_wb_rdata : mem_wb_result;

    always @(posedge clk) begin
        if (!rst && mem_wb_reg_write && mem_wb_rd != 0) begin
            regfile[mem_wb_rd] <= mem_wb_final_result;
        end
    end

endmodule
