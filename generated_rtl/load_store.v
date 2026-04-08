module load_store_unit(
    input  wire [31:0] addr,
    input  wire [31:0] wdata,
    input  wire [2:0]  funct3,
    input  wire        mem_read,
    input  wire        mem_write,
    output wire [31:0] rdata,
    output wire [3:0]  byte_en,
    output wire [31:0] mem_addr,
    output wire [31:0] mem_wdata
);
    assign mem_addr = addr;
 
    assign byte_en =
        !mem_write      ? 4'b0000 :
        funct3 == 3'b010 ? 4'b1111 :  
        funct3 == 3'b001 ? 4'b0011 :  
        funct3 == 3'b000 ? 4'b0001 :  
        4'b0000;

    assign mem_wdata =
        !mem_write       ? 32'b0 :
        funct3 == 3'b010 ? wdata :                          
        funct3 == 3'b001 ? {16'b0, wdata[15:0]} :           
        funct3 == 3'b000 ? {24'b0, wdata[7:0]} :            
        32'b0;
 
    assign rdata =
        !mem_read        ? 32'b0 :
        funct3 == 3'b010 ? wdata :                                        // LW
        funct3 == 3'b001 ? {{16{wdata[15]}}, wdata[15:0]} :               // LH signed
        funct3 == 3'b000 ? {{24{wdata[7]}},  wdata[7:0]}  :               // LB signed
        funct3 == 3'b101 ? {16'b0, wdata[15:0]} :                         // LHU unsigned
        funct3 == 3'b100 ? {24'b0, wdata[7:0]}  :                         // LBU unsigned
        32'b0;

endmodule