// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_pipeline__Syms.h"


VL_ATTR_COLD void Vriscv_pipeline___024root__trace_init_sub__TOP__0(Vriscv_pipeline___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+64,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+66,0,"instr_mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"instr_mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+68,0,"data_mem_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"data_mem_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"data_mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"data_mem_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"data_mem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("riscv_pipeline", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+64,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+66,0,"instr_mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"instr_mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+68,0,"data_mem_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"data_mem_re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"data_mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"data_mem_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"data_mem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"if_id_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+5,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+11+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+43,0,"id_ex_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"id_ex_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"id_ex_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"id_ex_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"id_ex_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+48,0,"id_ex_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+49,0,"id_ex_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+50,0,"ex_mem_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"ex_mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"ex_mem_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+53,0,"ex_mem_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"ex_mem_mem_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"ex_mem_mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"mem_wb_final_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"fwd_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"fwd_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"mem_wb_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"mem_wb_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"mem_wb_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+62,0,"mem_wb_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"mem_wb_mem_to_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_init_top(Vriscv_pipeline___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_init_top\n"); );
    // Body
    Vriscv_pipeline___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vriscv_pipeline___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vriscv_pipeline___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vriscv_pipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_register(Vriscv_pipeline___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vriscv_pipeline___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vriscv_pipeline___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vriscv_pipeline___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vriscv_pipeline___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_const_0\n"); );
    // Init
    Vriscv_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vriscv_pipeline___024root*>(voidSelf);
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_full_0_sub_0(Vriscv_pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_full_0\n"); );
    // Init
    Vriscv_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vriscv_pipeline___024root*>(voidSelf);
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vriscv_pipeline___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_full_0_sub_0(Vriscv_pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->riscv_pipeline__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->riscv_pipeline__DOT__pc),32);
    bufp->fullIData(oldp+3,(vlSelf->riscv_pipeline__DOT__if_id_instr),32);
    bufp->fullCData(oldp+4,((0x7fU & vlSelf->riscv_pipeline__DOT__if_id_instr)),7);
    bufp->fullCData(oldp+5,((7U & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                   >> 0xcU))),3);
    bufp->fullCData(oldp+6,((0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+7,((0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                      >> 0x14U))),5);
    bufp->fullCData(oldp+8,((0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                      >> 7U))),5);
    bufp->fullIData(oldp+9,((((- (IData)((vlSelf->riscv_pipeline__DOT__if_id_instr 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                          >> 0x14U))),32);
    bufp->fullIData(oldp+10,((((- (IData)((vlSelf->riscv_pipeline__DOT__if_id_instr 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                 >> 7U))))),32);
    bufp->fullIData(oldp+11,(vlSelf->riscv_pipeline__DOT__regfile[0]),32);
    bufp->fullIData(oldp+12,(vlSelf->riscv_pipeline__DOT__regfile[1]),32);
    bufp->fullIData(oldp+13,(vlSelf->riscv_pipeline__DOT__regfile[2]),32);
    bufp->fullIData(oldp+14,(vlSelf->riscv_pipeline__DOT__regfile[3]),32);
    bufp->fullIData(oldp+15,(vlSelf->riscv_pipeline__DOT__regfile[4]),32);
    bufp->fullIData(oldp+16,(vlSelf->riscv_pipeline__DOT__regfile[5]),32);
    bufp->fullIData(oldp+17,(vlSelf->riscv_pipeline__DOT__regfile[6]),32);
    bufp->fullIData(oldp+18,(vlSelf->riscv_pipeline__DOT__regfile[7]),32);
    bufp->fullIData(oldp+19,(vlSelf->riscv_pipeline__DOT__regfile[8]),32);
    bufp->fullIData(oldp+20,(vlSelf->riscv_pipeline__DOT__regfile[9]),32);
    bufp->fullIData(oldp+21,(vlSelf->riscv_pipeline__DOT__regfile[10]),32);
    bufp->fullIData(oldp+22,(vlSelf->riscv_pipeline__DOT__regfile[11]),32);
    bufp->fullIData(oldp+23,(vlSelf->riscv_pipeline__DOT__regfile[12]),32);
    bufp->fullIData(oldp+24,(vlSelf->riscv_pipeline__DOT__regfile[13]),32);
    bufp->fullIData(oldp+25,(vlSelf->riscv_pipeline__DOT__regfile[14]),32);
    bufp->fullIData(oldp+26,(vlSelf->riscv_pipeline__DOT__regfile[15]),32);
    bufp->fullIData(oldp+27,(vlSelf->riscv_pipeline__DOT__regfile[16]),32);
    bufp->fullIData(oldp+28,(vlSelf->riscv_pipeline__DOT__regfile[17]),32);
    bufp->fullIData(oldp+29,(vlSelf->riscv_pipeline__DOT__regfile[18]),32);
    bufp->fullIData(oldp+30,(vlSelf->riscv_pipeline__DOT__regfile[19]),32);
    bufp->fullIData(oldp+31,(vlSelf->riscv_pipeline__DOT__regfile[20]),32);
    bufp->fullIData(oldp+32,(vlSelf->riscv_pipeline__DOT__regfile[21]),32);
    bufp->fullIData(oldp+33,(vlSelf->riscv_pipeline__DOT__regfile[22]),32);
    bufp->fullIData(oldp+34,(vlSelf->riscv_pipeline__DOT__regfile[23]),32);
    bufp->fullIData(oldp+35,(vlSelf->riscv_pipeline__DOT__regfile[24]),32);
    bufp->fullIData(oldp+36,(vlSelf->riscv_pipeline__DOT__regfile[25]),32);
    bufp->fullIData(oldp+37,(vlSelf->riscv_pipeline__DOT__regfile[26]),32);
    bufp->fullIData(oldp+38,(vlSelf->riscv_pipeline__DOT__regfile[27]),32);
    bufp->fullIData(oldp+39,(vlSelf->riscv_pipeline__DOT__regfile[28]),32);
    bufp->fullIData(oldp+40,(vlSelf->riscv_pipeline__DOT__regfile[29]),32);
    bufp->fullIData(oldp+41,(vlSelf->riscv_pipeline__DOT__regfile[30]),32);
    bufp->fullIData(oldp+42,(vlSelf->riscv_pipeline__DOT__regfile[31]),32);
    bufp->fullIData(oldp+43,(vlSelf->riscv_pipeline__DOT__id_ex_rs1_data),32);
    bufp->fullIData(oldp+44,(vlSelf->riscv_pipeline__DOT__id_ex_rs2_data),32);
    bufp->fullIData(oldp+45,(vlSelf->riscv_pipeline__DOT__id_ex_imm),32);
    bufp->fullCData(oldp+46,(vlSelf->riscv_pipeline__DOT__id_ex_rd),5);
    bufp->fullCData(oldp+47,(vlSelf->riscv_pipeline__DOT__id_ex_rs1),5);
    bufp->fullCData(oldp+48,(vlSelf->riscv_pipeline__DOT__id_ex_rs2),5);
    bufp->fullCData(oldp+49,(vlSelf->riscv_pipeline__DOT__id_ex_opcode),7);
    bufp->fullIData(oldp+50,(vlSelf->riscv_pipeline__DOT__ex_mem_result),32);
    bufp->fullIData(oldp+51,(vlSelf->riscv_pipeline__DOT__ex_mem_wdata),32);
    bufp->fullCData(oldp+52,(vlSelf->riscv_pipeline__DOT__ex_mem_rd),5);
    bufp->fullBit(oldp+53,(vlSelf->riscv_pipeline__DOT__ex_mem_reg_write));
    bufp->fullBit(oldp+54,(vlSelf->riscv_pipeline__DOT__ex_mem_mem_re));
    bufp->fullBit(oldp+55,(vlSelf->riscv_pipeline__DOT__ex_mem_mem_we));
    bufp->fullIData(oldp+56,(vlSelf->riscv_pipeline__DOT__mem_wb_final_result),32);
    bufp->fullIData(oldp+57,(vlSelf->riscv_pipeline__DOT__fwd_a),32);
    bufp->fullIData(oldp+58,(vlSelf->riscv_pipeline__DOT__fwd_b),32);
    bufp->fullIData(oldp+59,(vlSelf->riscv_pipeline__DOT__mem_wb_result),32);
    bufp->fullIData(oldp+60,(vlSelf->riscv_pipeline__DOT__mem_wb_rdata),32);
    bufp->fullCData(oldp+61,(vlSelf->riscv_pipeline__DOT__mem_wb_rd),5);
    bufp->fullBit(oldp+62,(vlSelf->riscv_pipeline__DOT__mem_wb_reg_write));
    bufp->fullBit(oldp+63,(vlSelf->riscv_pipeline__DOT__mem_wb_mem_to_reg));
    bufp->fullBit(oldp+64,(vlSelf->clk));
    bufp->fullBit(oldp+65,(vlSelf->rst));
    bufp->fullIData(oldp+66,(vlSelf->instr_mem_addr),32);
    bufp->fullIData(oldp+67,(vlSelf->instr_mem_data),32);
    bufp->fullBit(oldp+68,(vlSelf->data_mem_we));
    bufp->fullBit(oldp+69,(vlSelf->data_mem_re));
    bufp->fullIData(oldp+70,(vlSelf->data_mem_addr),32);
    bufp->fullIData(oldp+71,(vlSelf->data_mem_wdata),32);
    bufp->fullIData(oldp+72,(vlSelf->data_mem_rdata),32);
}
