// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vload_store_unit.h for the primary calling header

#include "Vload_store_unit__pch.h"
#include "Vload_store_unit___024root.h"

VL_ATTR_COLD void Vload_store_unit___024root___eval_static(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vload_store_unit___024root___eval_initial(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Vload_store_unit___024root___eval_final(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__stl(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vload_store_unit___024root___eval_phase__stl(Vload_store_unit___024root* vlSelf);

VL_ATTR_COLD void Vload_store_unit___024root___eval_settle(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vload_store_unit___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/load_store.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vload_store_unit___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__stl(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vload_store_unit___024root___ico_sequent__TOP__0(Vload_store_unit___024root* vlSelf);

VL_ATTR_COLD void Vload_store_unit___024root___eval_stl(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vload_store_unit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vload_store_unit___024root___eval_triggers__stl(Vload_store_unit___024root* vlSelf);

VL_ATTR_COLD bool Vload_store_unit___024root___eval_phase__stl(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vload_store_unit___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vload_store_unit___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__ico(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__act(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__nba(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vload_store_unit___024root___ctor_var_reset(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->addr = VL_RAND_RESET_I(32);
    vlSelf->wdata = VL_RAND_RESET_I(32);
    vlSelf->funct3 = VL_RAND_RESET_I(3);
    vlSelf->mem_read = VL_RAND_RESET_I(1);
    vlSelf->mem_write = VL_RAND_RESET_I(1);
    vlSelf->rdata = VL_RAND_RESET_I(32);
    vlSelf->byte_en = VL_RAND_RESET_I(4);
    vlSelf->mem_addr = VL_RAND_RESET_I(32);
    vlSelf->mem_wdata = VL_RAND_RESET_I(32);
}
