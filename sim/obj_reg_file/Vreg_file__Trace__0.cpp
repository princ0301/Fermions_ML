// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vreg_file__Syms.h"


void Vreg_file___024root__trace_chg_0_sub_0(Vreg_file___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vreg_file___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_chg_0\n"); );
    // Init
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vreg_file___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vreg_file___024root__trace_chg_0_sub_0(Vreg_file___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->reg_file__DOT__regs[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->reg_file__DOT__regs[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->reg_file__DOT__regs[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->reg_file__DOT__regs[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->reg_file__DOT__regs[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->reg_file__DOT__regs[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->reg_file__DOT__regs[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->reg_file__DOT__regs[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->reg_file__DOT__regs[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->reg_file__DOT__regs[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->reg_file__DOT__regs[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->reg_file__DOT__regs[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->reg_file__DOT__regs[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->reg_file__DOT__regs[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->reg_file__DOT__regs[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->reg_file__DOT__regs[15]),32);
        bufp->chgIData(oldp+16,(vlSelf->reg_file__DOT__regs[16]),32);
        bufp->chgIData(oldp+17,(vlSelf->reg_file__DOT__regs[17]),32);
        bufp->chgIData(oldp+18,(vlSelf->reg_file__DOT__regs[18]),32);
        bufp->chgIData(oldp+19,(vlSelf->reg_file__DOT__regs[19]),32);
        bufp->chgIData(oldp+20,(vlSelf->reg_file__DOT__regs[20]),32);
        bufp->chgIData(oldp+21,(vlSelf->reg_file__DOT__regs[21]),32);
        bufp->chgIData(oldp+22,(vlSelf->reg_file__DOT__regs[22]),32);
        bufp->chgIData(oldp+23,(vlSelf->reg_file__DOT__regs[23]),32);
        bufp->chgIData(oldp+24,(vlSelf->reg_file__DOT__regs[24]),32);
        bufp->chgIData(oldp+25,(vlSelf->reg_file__DOT__regs[25]),32);
        bufp->chgIData(oldp+26,(vlSelf->reg_file__DOT__regs[26]),32);
        bufp->chgIData(oldp+27,(vlSelf->reg_file__DOT__regs[27]),32);
        bufp->chgIData(oldp+28,(vlSelf->reg_file__DOT__regs[28]),32);
        bufp->chgIData(oldp+29,(vlSelf->reg_file__DOT__regs[29]),32);
        bufp->chgIData(oldp+30,(vlSelf->reg_file__DOT__regs[30]),32);
        bufp->chgIData(oldp+31,(vlSelf->reg_file__DOT__regs[31]),32);
        bufp->chgIData(oldp+32,(vlSelf->reg_file__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+33,(vlSelf->clk));
    bufp->chgBit(oldp+34,(vlSelf->rst));
    bufp->chgBit(oldp+35,(vlSelf->we));
    bufp->chgCData(oldp+36,(vlSelf->rs1),5);
    bufp->chgCData(oldp+37,(vlSelf->rs2),5);
    bufp->chgCData(oldp+38,(vlSelf->rd),5);
    bufp->chgIData(oldp+39,(vlSelf->wdata),32);
    bufp->chgIData(oldp+40,(vlSelf->rdata1),32);
    bufp->chgIData(oldp+41,(vlSelf->rdata2),32);
}

void Vreg_file___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root__trace_cleanup\n"); );
    // Init
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
