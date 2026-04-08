// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vprogram_counter__Syms.h"


void Vprogram_counter___024root__trace_chg_0_sub_0(Vprogram_counter___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vprogram_counter___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root__trace_chg_0\n"); );
    // Init
    Vprogram_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprogram_counter___024root*>(voidSelf);
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vprogram_counter___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vprogram_counter___024root__trace_chg_0_sub_0(Vprogram_counter___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgBit(oldp+2,(vlSelf->stall));
    bufp->chgBit(oldp+3,(vlSelf->branch_taken));
    bufp->chgIData(oldp+4,(vlSelf->branch_target),32);
    bufp->chgBit(oldp+5,(vlSelf->jump_taken));
    bufp->chgIData(oldp+6,(vlSelf->jump_target),32);
    bufp->chgIData(oldp+7,(vlSelf->pc),32);
    bufp->chgIData(oldp+8,(vlSelf->next_pc),32);
    bufp->chgIData(oldp+9,(vlSelf->program_counter__DOT__pc_reg),32);
}

void Vprogram_counter___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root__trace_cleanup\n"); );
    // Init
    Vprogram_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprogram_counter___024root*>(voidSelf);
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
