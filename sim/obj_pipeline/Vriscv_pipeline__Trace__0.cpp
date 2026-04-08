// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_pipeline__Syms.h"


void Vriscv_pipeline___024root__trace_chg_0_sub_0(Vriscv_pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vriscv_pipeline___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_chg_0\n"); );
    // Init
    Vriscv_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vriscv_pipeline___024root*>(voidSelf);
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vriscv_pipeline___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vriscv_pipeline___024root__trace_chg_0_sub_0(Vriscv_pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->riscv_pipeline__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(vlSelf->riscv_pipeline__DOT__pc),32);
        bufp->chgIData(oldp+2,(vlSelf->riscv_pipeline__DOT__if_id_instr),32);
        bufp->chgCData(oldp+3,((0x7fU & vlSelf->riscv_pipeline__DOT__if_id_instr)),7);
        bufp->chgCData(oldp+4,((7U & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                      >> 0xcU))),3);
        bufp->chgCData(oldp+5,((0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+6,((0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+7,((0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                         >> 7U))),5);
        bufp->chgIData(oldp+8,((((- (IData)((vlSelf->riscv_pipeline__DOT__if_id_instr 
                                             >> 0x1fU))) 
                                 << 0xcU) | (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                             >> 0x14U))),32);
        bufp->chgIData(oldp+9,((((- (IData)((vlSelf->riscv_pipeline__DOT__if_id_instr 
                                             >> 0x1fU))) 
                                 << 0xcU) | ((0xfe0U 
                                              & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                   >> 7U))))),32);
        bufp->chgIData(oldp+10,(vlSelf->riscv_pipeline__DOT__regfile[0]),32);
        bufp->chgIData(oldp+11,(vlSelf->riscv_pipeline__DOT__regfile[1]),32);
        bufp->chgIData(oldp+12,(vlSelf->riscv_pipeline__DOT__regfile[2]),32);
        bufp->chgIData(oldp+13,(vlSelf->riscv_pipeline__DOT__regfile[3]),32);
        bufp->chgIData(oldp+14,(vlSelf->riscv_pipeline__DOT__regfile[4]),32);
        bufp->chgIData(oldp+15,(vlSelf->riscv_pipeline__DOT__regfile[5]),32);
        bufp->chgIData(oldp+16,(vlSelf->riscv_pipeline__DOT__regfile[6]),32);
        bufp->chgIData(oldp+17,(vlSelf->riscv_pipeline__DOT__regfile[7]),32);
        bufp->chgIData(oldp+18,(vlSelf->riscv_pipeline__DOT__regfile[8]),32);
        bufp->chgIData(oldp+19,(vlSelf->riscv_pipeline__DOT__regfile[9]),32);
        bufp->chgIData(oldp+20,(vlSelf->riscv_pipeline__DOT__regfile[10]),32);
        bufp->chgIData(oldp+21,(vlSelf->riscv_pipeline__DOT__regfile[11]),32);
        bufp->chgIData(oldp+22,(vlSelf->riscv_pipeline__DOT__regfile[12]),32);
        bufp->chgIData(oldp+23,(vlSelf->riscv_pipeline__DOT__regfile[13]),32);
        bufp->chgIData(oldp+24,(vlSelf->riscv_pipeline__DOT__regfile[14]),32);
        bufp->chgIData(oldp+25,(vlSelf->riscv_pipeline__DOT__regfile[15]),32);
        bufp->chgIData(oldp+26,(vlSelf->riscv_pipeline__DOT__regfile[16]),32);
        bufp->chgIData(oldp+27,(vlSelf->riscv_pipeline__DOT__regfile[17]),32);
        bufp->chgIData(oldp+28,(vlSelf->riscv_pipeline__DOT__regfile[18]),32);
        bufp->chgIData(oldp+29,(vlSelf->riscv_pipeline__DOT__regfile[19]),32);
        bufp->chgIData(oldp+30,(vlSelf->riscv_pipeline__DOT__regfile[20]),32);
        bufp->chgIData(oldp+31,(vlSelf->riscv_pipeline__DOT__regfile[21]),32);
        bufp->chgIData(oldp+32,(vlSelf->riscv_pipeline__DOT__regfile[22]),32);
        bufp->chgIData(oldp+33,(vlSelf->riscv_pipeline__DOT__regfile[23]),32);
        bufp->chgIData(oldp+34,(vlSelf->riscv_pipeline__DOT__regfile[24]),32);
        bufp->chgIData(oldp+35,(vlSelf->riscv_pipeline__DOT__regfile[25]),32);
        bufp->chgIData(oldp+36,(vlSelf->riscv_pipeline__DOT__regfile[26]),32);
        bufp->chgIData(oldp+37,(vlSelf->riscv_pipeline__DOT__regfile[27]),32);
        bufp->chgIData(oldp+38,(vlSelf->riscv_pipeline__DOT__regfile[28]),32);
        bufp->chgIData(oldp+39,(vlSelf->riscv_pipeline__DOT__regfile[29]),32);
        bufp->chgIData(oldp+40,(vlSelf->riscv_pipeline__DOT__regfile[30]),32);
        bufp->chgIData(oldp+41,(vlSelf->riscv_pipeline__DOT__regfile[31]),32);
        bufp->chgIData(oldp+42,(vlSelf->riscv_pipeline__DOT__id_ex_rs1_data),32);
        bufp->chgIData(oldp+43,(vlSelf->riscv_pipeline__DOT__id_ex_rs2_data),32);
        bufp->chgIData(oldp+44,(vlSelf->riscv_pipeline__DOT__id_ex_imm),32);
        bufp->chgCData(oldp+45,(vlSelf->riscv_pipeline__DOT__id_ex_rd),5);
        bufp->chgCData(oldp+46,(vlSelf->riscv_pipeline__DOT__id_ex_rs1),5);
        bufp->chgCData(oldp+47,(vlSelf->riscv_pipeline__DOT__id_ex_rs2),5);
        bufp->chgCData(oldp+48,(vlSelf->riscv_pipeline__DOT__id_ex_opcode),7);
        bufp->chgIData(oldp+49,(vlSelf->riscv_pipeline__DOT__ex_mem_result),32);
        bufp->chgIData(oldp+50,(vlSelf->riscv_pipeline__DOT__ex_mem_wdata),32);
        bufp->chgCData(oldp+51,(vlSelf->riscv_pipeline__DOT__ex_mem_rd),5);
        bufp->chgBit(oldp+52,(vlSelf->riscv_pipeline__DOT__ex_mem_reg_write));
        bufp->chgBit(oldp+53,(vlSelf->riscv_pipeline__DOT__ex_mem_mem_re));
        bufp->chgBit(oldp+54,(vlSelf->riscv_pipeline__DOT__ex_mem_mem_we));
        bufp->chgIData(oldp+55,(vlSelf->riscv_pipeline__DOT__mem_wb_final_result),32);
        bufp->chgIData(oldp+56,(vlSelf->riscv_pipeline__DOT__fwd_a),32);
        bufp->chgIData(oldp+57,(vlSelf->riscv_pipeline__DOT__fwd_b),32);
        bufp->chgIData(oldp+58,(vlSelf->riscv_pipeline__DOT__mem_wb_result),32);
        bufp->chgIData(oldp+59,(vlSelf->riscv_pipeline__DOT__mem_wb_rdata),32);
        bufp->chgCData(oldp+60,(vlSelf->riscv_pipeline__DOT__mem_wb_rd),5);
        bufp->chgBit(oldp+61,(vlSelf->riscv_pipeline__DOT__mem_wb_reg_write));
        bufp->chgBit(oldp+62,(vlSelf->riscv_pipeline__DOT__mem_wb_mem_to_reg));
    }
    bufp->chgBit(oldp+63,(vlSelf->clk));
    bufp->chgBit(oldp+64,(vlSelf->rst));
    bufp->chgIData(oldp+65,(vlSelf->instr_mem_addr),32);
    bufp->chgIData(oldp+66,(vlSelf->instr_mem_data),32);
    bufp->chgBit(oldp+67,(vlSelf->data_mem_we));
    bufp->chgBit(oldp+68,(vlSelf->data_mem_re));
    bufp->chgIData(oldp+69,(vlSelf->data_mem_addr),32);
    bufp->chgIData(oldp+70,(vlSelf->data_mem_wdata),32);
    bufp->chgIData(oldp+71,(vlSelf->data_mem_rdata),32);
}

void Vriscv_pipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root__trace_cleanup\n"); );
    // Init
    Vriscv_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vriscv_pipeline___024root*>(voidSelf);
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
