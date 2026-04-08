// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprogram_counter.h for the primary calling header

#include "Vprogram_counter__pch.h"
#include "Vprogram_counter___024root.h"

void Vprogram_counter___024root___eval_act(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vprogram_counter___024root___nba_sequent__TOP__0(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->program_counter__DOT__pc_reg = ((IData)(vlSelf->rst)
                                             ? 0U : 
                                            ((IData)(vlSelf->stall)
                                              ? vlSelf->program_counter__DOT__pc_reg
                                              : ((IData)(vlSelf->branch_taken)
                                                  ? vlSelf->branch_target
                                                  : 
                                                 ((IData)(vlSelf->jump_taken)
                                                   ? vlSelf->jump_target
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelf->program_counter__DOT__pc_reg)))));
    vlSelf->pc = vlSelf->program_counter__DOT__pc_reg;
    vlSelf->next_pc = ((IData)(4U) + vlSelf->program_counter__DOT__pc_reg);
}

void Vprogram_counter___024root___eval_nba(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vprogram_counter___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vprogram_counter___024root___eval_triggers__act(Vprogram_counter___024root* vlSelf);

bool Vprogram_counter___024root___eval_phase__act(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vprogram_counter___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vprogram_counter___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vprogram_counter___024root___eval_phase__nba(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vprogram_counter___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprogram_counter___024root___dump_triggers__nba(Vprogram_counter___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vprogram_counter___024root___dump_triggers__act(Vprogram_counter___024root* vlSelf);
#endif  // VL_DEBUG

void Vprogram_counter___024root___eval(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vprogram_counter___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/pc.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vprogram_counter___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("generated_rtl/pc.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vprogram_counter___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vprogram_counter___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vprogram_counter___024root___eval_debug_assertions(Vprogram_counter___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->stall & 0xfeU))) {
        Verilated::overWidthError("stall");}
    if (VL_UNLIKELY((vlSelf->branch_taken & 0xfeU))) {
        Verilated::overWidthError("branch_taken");}
    if (VL_UNLIKELY((vlSelf->jump_taken & 0xfeU))) {
        Verilated::overWidthError("jump_taken");}
}
#endif  // VL_DEBUG
