// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch_unit.h for the primary calling header

#include "Vbranch_unit__pch.h"
#include "Vbranch_unit___024root.h"

VL_INLINE_OPT void Vbranch_unit___024root___ico_sequent__TOP__0(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->branch_taken = ((4U & (IData)(vlSelf->funct3))
                             ? ((2U & (IData)(vlSelf->funct3))
                                 ? ((1U & (IData)(vlSelf->funct3))
                                     ? (vlSelf->rs1_val 
                                        >= vlSelf->rs2_val)
                                     : (vlSelf->rs1_val 
                                        < vlSelf->rs2_val))
                                 : ((1U & (IData)(vlSelf->funct3))
                                     ? VL_GTES_III(32, vlSelf->rs1_val, vlSelf->rs2_val)
                                     : VL_LTS_III(32, vlSelf->rs1_val, vlSelf->rs2_val)))
                             : ((1U & (~ ((IData)(vlSelf->funct3) 
                                          >> 1U))) 
                                && ((1U & (IData)(vlSelf->funct3))
                                     ? (vlSelf->rs1_val 
                                        != vlSelf->rs2_val)
                                     : (vlSelf->rs1_val 
                                        == vlSelf->rs2_val))));
}

void Vbranch_unit___024root___eval_ico(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vbranch_unit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vbranch_unit___024root___eval_triggers__ico(Vbranch_unit___024root* vlSelf);

bool Vbranch_unit___024root___eval_phase__ico(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vbranch_unit___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vbranch_unit___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vbranch_unit___024root___eval_act(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_act\n"); );
}

void Vbranch_unit___024root___eval_nba(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_nba\n"); );
}

void Vbranch_unit___024root___eval_triggers__act(Vbranch_unit___024root* vlSelf);

bool Vbranch_unit___024root___eval_phase__act(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbranch_unit___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vbranch_unit___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbranch_unit___024root___eval_phase__nba(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbranch_unit___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch_unit___024root___dump_triggers__ico(Vbranch_unit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch_unit___024root___dump_triggers__nba(Vbranch_unit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch_unit___024root___dump_triggers__act(Vbranch_unit___024root* vlSelf);
#endif  // VL_DEBUG

void Vbranch_unit___024root___eval(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vbranch_unit___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/branch_unit.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vbranch_unit___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vbranch_unit___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/branch_unit.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vbranch_unit___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("generated_rtl/branch_unit.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vbranch_unit___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vbranch_unit___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbranch_unit___024root___eval_debug_assertions(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->funct3 & 0xf8U))) {
        Verilated::overWidthError("funct3");}
    if (VL_UNLIKELY((vlSelf->is_branch & 0xfeU))) {
        Verilated::overWidthError("is_branch");}
}
#endif  // VL_DEBUG
