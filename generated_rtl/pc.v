module program_counter(
    input  clk,
    input  rst,
    input  stall,
    input  branch_taken,
    input  [31:0] branch_target,
    input  jump_taken,
    input  [31:0] jump_target,
    output [31:0] pc,
    output [31:0] next_pc
);

reg [31:0] pc_reg;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        pc_reg <= 32'd0;
    end else if (stall) begin
        pc_reg <= pc_reg;
    end else if (branch_taken) begin
        pc_reg <= branch_target;
    end else if (jump_taken) begin
        pc_reg <= jump_target;
    end else begin
        pc_reg <= pc_reg + 32'd4;
    end
end

assign pc = pc_reg;
assign next_pc = pc_reg + 32'd4;

endmodule
