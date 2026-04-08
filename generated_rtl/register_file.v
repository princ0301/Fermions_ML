module reg_file (
    input clk,
    input rst,
    input we,
    input [4:0] rs1, rs2, rd,
    input [31:0] wdata,
    output [31:0] rdata1, rdata2
);
    reg [31:0] regs [0:31];
    assign rdata1 = (rs1 == 5'b0) ? 32'b0 : regs[rs1];
    assign rdata2 = (rs2 == 5'b0) ? 32'b0 : regs[rs2];
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int i = 1; i < 32; i++) begin
                regs[i] <= 32'b0;
            end
        end else if (we && rd != 5'b0) begin
            regs[rd] <= wdata;
        end
    end
endmodule
