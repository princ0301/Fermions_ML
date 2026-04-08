// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_file.h for the primary calling header

#include "Vreg_file__pch.h"
#include "Vreg_file___024root.h"

VL_INLINE_OPT void Vreg_file___024root___ico_sequent__TOP__0(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->rdata1 = ((0U == (IData)(vlSelf->rs1)) ? 0U
                       : vlSelf->reg_file__DOT__regs
                      [vlSelf->rs1]);
    vlSelf->rdata2 = ((0U == (IData)(vlSelf->rs2)) ? 0U
                       : vlSelf->reg_file__DOT__regs
                      [vlSelf->rs2]);
}

void Vreg_file___024root___eval_ico(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vreg_file___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vreg_file___024root___eval_triggers__ico(Vreg_file___024root* vlSelf);

bool Vreg_file___024root___eval_phase__ico(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vreg_file___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vreg_file___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vreg_file___024root___eval_act(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vreg_file___024root___nba_sequent__TOP__0(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__reg_file__DOT__regs__v0;
    __Vdlyvset__reg_file__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__reg_file__DOT__regs__v31;
    __Vdlyvdim0__reg_file__DOT__regs__v31 = 0;
    IData/*31:0*/ __Vdlyvval__reg_file__DOT__regs__v31;
    __Vdlyvval__reg_file__DOT__regs__v31 = 0;
    CData/*0:0*/ __Vdlyvset__reg_file__DOT__regs__v31;
    __Vdlyvset__reg_file__DOT__regs__v31 = 0;
    // Body
    __Vdlyvset__reg_file__DOT__regs__v0 = 0U;
    __Vdlyvset__reg_file__DOT__regs__v31 = 0U;
    if (vlSelf->rst) {
        vlSelf->reg_file__DOT__unnamedblk1__DOT__i = 0x20U;
        __Vdlyvset__reg_file__DOT__regs__v0 = 1U;
    } else if (((IData)(vlSelf->we) & (0U != (IData)(vlSelf->rd)))) {
        __Vdlyvval__reg_file__DOT__regs__v31 = vlSelf->wdata;
        __Vdlyvset__reg_file__DOT__regs__v31 = 1U;
        __Vdlyvdim0__reg_file__DOT__regs__v31 = vlSelf->rd;
    }
    if (__Vdlyvset__reg_file__DOT__regs__v0) {
        vlSelf->reg_file__DOT__regs[1U] = 0U;
        vlSelf->reg_file__DOT__regs[2U] = 0U;
        vlSelf->reg_file__DOT__regs[3U] = 0U;
        vlSelf->reg_file__DOT__regs[4U] = 0U;
        vlSelf->reg_file__DOT__regs[5U] = 0U;
        vlSelf->reg_file__DOT__regs[6U] = 0U;
        vlSelf->reg_file__DOT__regs[7U] = 0U;
        vlSelf->reg_file__DOT__regs[8U] = 0U;
        vlSelf->reg_file__DOT__regs[9U] = 0U;
        vlSelf->reg_file__DOT__regs[0xaU] = 0U;
        vlSelf->reg_file__DOT__regs[0xbU] = 0U;
        vlSelf->reg_file__DOT__regs[0xcU] = 0U;
        vlSelf->reg_file__DOT__regs[0xdU] = 0U;
        vlSelf->reg_file__DOT__regs[0xeU] = 0U;
        vlSelf->reg_file__DOT__regs[0xfU] = 0U;
        vlSelf->reg_file__DOT__regs[0x10U] = 0U;
        vlSelf->reg_file__DOT__regs[0x11U] = 0U;
        vlSelf->reg_file__DOT__regs[0x12U] = 0U;
        vlSelf->reg_file__DOT__regs[0x13U] = 0U;
        vlSelf->reg_file__DOT__regs[0x14U] = 0U;
        vlSelf->reg_file__DOT__regs[0x15U] = 0U;
        vlSelf->reg_file__DOT__regs[0x16U] = 0U;
        vlSelf->reg_file__DOT__regs[0x17U] = 0U;
        vlSelf->reg_file__DOT__regs[0x18U] = 0U;
        vlSelf->reg_file__DOT__regs[0x19U] = 0U;
        vlSelf->reg_file__DOT__regs[0x1aU] = 0U;
        vlSelf->reg_file__DOT__regs[0x1bU] = 0U;
        vlSelf->reg_file__DOT__regs[0x1cU] = 0U;
        vlSelf->reg_file__DOT__regs[0x1dU] = 0U;
        vlSelf->reg_file__DOT__regs[0x1eU] = 0U;
        vlSelf->reg_file__DOT__regs[0x1fU] = 0U;
    }
    if (__Vdlyvset__reg_file__DOT__regs__v31) {
        vlSelf->reg_file__DOT__regs[__Vdlyvdim0__reg_file__DOT__regs__v31] 
            = __Vdlyvval__reg_file__DOT__regs__v31;
    }
    vlSelf->rdata1 = ((0U == (IData)(vlSelf->rs1)) ? 0U
                       : vlSelf->reg_file__DOT__regs
                      [vlSelf->rs1]);
    vlSelf->rdata2 = ((0U == (IData)(vlSelf->rs2)) ? 0U
                       : vlSelf->reg_file__DOT__regs
                      [vlSelf->rs2]);
}

void Vreg_file___024root___eval_nba(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vreg_file___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vreg_file___024root___eval_triggers__act(Vreg_file___024root* vlSelf);

bool Vreg_file___024root___eval_phase__act(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vreg_file___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vreg_file___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vreg_file___024root___eval_phase__nba(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vreg_file___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_file___024root___dump_triggers__ico(Vreg_file___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_file___024root___dump_triggers__nba(Vreg_file___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_file___024root___dump_triggers__act(Vreg_file___024root* vlSelf);
#endif  // VL_DEBUG

void Vreg_file___024root___eval(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval\n"); );
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
            Vreg_file___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/register_file.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vreg_file___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vreg_file___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/register_file.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vreg_file___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("generated_rtl/register_file.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vreg_file___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vreg_file___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vreg_file___024root___eval_debug_assertions(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelf->rs1 & 0xe0U))) {
        Verilated::overWidthError("rs1");}
    if (VL_UNLIKELY((vlSelf->rs2 & 0xe0U))) {
        Verilated::overWidthError("rs2");}
    if (VL_UNLIKELY((vlSelf->rd & 0xe0U))) {
        Verilated::overWidthError("rd");}
}
#endif  // VL_DEBUG
