module branch_unit(
    input  wire [31:0] rs1_val,
    input  wire [31:0] rs2_val,
    input  wire [2:0]  funct3,
    input  wire        is_branch,
    output reg        branch_taken
);

always @(*) begin
    case (funct3)
        3'b000: branch_taken = (rs1_val == rs2_val);              
        3'b001: branch_taken = (rs1_val != rs2_val);              
        3'b100: branch_taken = ($signed(rs1_val) < $signed(rs2_val)); 
        3'b101: branch_taken = ($signed(rs1_val) >= $signed(rs2_val)); 
        3'b110: branch_taken = (rs1_val < rs2_val);                
        3'b111: branch_taken = (rs1_val >= rs2_val);               
        default: branch_taken = 0;
    endcase
end

endmodule

