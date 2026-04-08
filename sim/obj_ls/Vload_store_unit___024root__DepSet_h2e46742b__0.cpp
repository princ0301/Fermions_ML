// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vload_store_unit.h for the primary calling header

#include "Vload_store_unit__pch.h"
#include "Vload_store_unit___024root.h"

VL_INLINE_OPT void Vload_store_unit___024root___ico_sequent__TOP__0(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->mem_addr = vlSelf->addr;
    if (vlSelf->mem_write) {
        if ((2U == (IData)(vlSelf->funct3))) {
            vlSelf->byte_en = 0xfU;
            vlSelf->mem_wdata = vlSelf->wdata;
        } else if ((1U == (IData)(vlSelf->funct3))) {
            vlSelf->byte_en = 3U;
            vlSelf->mem_wdata = (0xffffU & vlSelf->wdata);
        } else if ((0U == (IData)(vlSelf->funct3))) {
            vlSelf->byte_en = 1U;
            vlSelf->mem_wdata = (0xffU & vlSelf->wdata);
        } else {
            vlSelf->byte_en = 0U;
            vlSelf->mem_wdata = 0U;
        }
    } else {
        vlSelf->byte_en = 0U;
        vlSelf->mem_wdata = 0U;
    }
    vlSelf->rdata = ((IData)(vlSelf->mem_read) ? ((2U 
                                                   == (IData)(vlSelf->funct3))
                                                   ? vlSelf->wdata
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlSelf->funct3))
                                                    ? 
                                                   (((- (IData)(
                                                                (1U 
                                                                 & (vlSelf->wdata 
                                                                    >> 0xfU)))) 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & vlSelf->wdata))
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlSelf->funct3))
                                                     ? 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->wdata 
                                                                     >> 7U)))) 
                                                      << 8U) 
                                                     | (0xffU 
                                                        & vlSelf->wdata))
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelf->funct3))
                                                      ? 
                                                     (0xffffU 
                                                      & vlSelf->wdata)
                                                      : 
                                                     ((4U 
                                                       == (IData)(vlSelf->funct3))
                                                       ? 
                                                      (0xffU 
                                                       & vlSelf->wdata)
                                                       : 0U)))))
                      : 0U);
}

void Vload_store_unit___024root___eval_ico(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vload_store_unit___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vload_store_unit___024root___eval_triggers__ico(Vload_store_unit___024root* vlSelf);

bool Vload_store_unit___024root___eval_phase__ico(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vload_store_unit___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vload_store_unit___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vload_store_unit___024root___eval_act(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_act\n"); );
}

void Vload_store_unit___024root___eval_nba(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_nba\n"); );
}

void Vload_store_unit___024root___eval_triggers__act(Vload_store_unit___024root* vlSelf);

bool Vload_store_unit___024root___eval_phase__act(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vload_store_unit___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vload_store_unit___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vload_store_unit___024root___eval_phase__nba(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vload_store_unit___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__ico(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__nba(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__act(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG

void Vload_store_unit___024root___eval(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval\n"); );
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
            Vload_store_unit___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/load_store.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vload_store_unit___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vload_store_unit___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/load_store.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vload_store_unit___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("generated_rtl/load_store.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vload_store_unit___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vload_store_unit___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vload_store_unit___024root___eval_debug_assertions(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->funct3 & 0xf8U))) {
        Verilated::overWidthError("funct3");}
    if (VL_UNLIKELY((vlSelf->mem_read & 0xfeU))) {
        Verilated::overWidthError("mem_read");}
    if (VL_UNLIKELY((vlSelf->mem_write & 0xfeU))) {
        Verilated::overWidthError("mem_write");}
}
#endif  // VL_DEBUG
