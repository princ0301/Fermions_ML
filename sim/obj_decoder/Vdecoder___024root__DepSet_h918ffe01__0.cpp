// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecoder.h for the primary calling header

#include "Vdecoder__pch.h"
#include "Vdecoder___024root.h"

VL_INLINE_OPT void Vdecoder___024root___ico_sequent__TOP__0(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ decoder__DOT____VdfgTmp_hcdfb786b__0;
    decoder__DOT____VdfgTmp_hcdfb786b__0 = 0;
    CData/*0:0*/ decoder__DOT____VdfgTmp_hbed6aa0b__0;
    decoder__DOT____VdfgTmp_hbed6aa0b__0 = 0;
    CData/*0:0*/ decoder__DOT____VdfgTmp_hfb99b22b__0;
    decoder__DOT____VdfgTmp_hfb99b22b__0 = 0;
    // Body
    vlSelf->rs1 = (0x1fU & (vlSelf->inst >> 0xfU));
    vlSelf->rs2 = (0x1fU & (vlSelf->inst >> 0x14U));
    vlSelf->funct3 = (7U & (vlSelf->inst >> 0xcU));
    vlSelf->funct7 = (vlSelf->inst >> 0x19U);
    vlSelf->rd = (0x1fU & (vlSelf->inst >> 7U));
    vlSelf->opcode = (0x7fU & vlSelf->inst);
    vlSelf->jump = ((0x6fU == (IData)(vlSelf->opcode)) 
                    | (0x67U == (IData)(vlSelf->opcode)));
    decoder__DOT____VdfgTmp_hbed6aa0b__0 = ((0x33U 
                                             == (IData)(vlSelf->opcode)) 
                                            | (0x13U 
                                               == (IData)(vlSelf->opcode)));
    vlSelf->mem_write = (0x23U == (IData)(vlSelf->opcode));
    vlSelf->branch = (0x63U == (IData)(vlSelf->opcode));
    vlSelf->mem_read = (3U == (IData)(vlSelf->opcode));
    decoder__DOT____VdfgTmp_hcdfb786b__0 = ((0x37U 
                                             == (IData)(vlSelf->opcode)) 
                                            | (0x17U 
                                               == (IData)(vlSelf->opcode)));
    vlSelf->alu_op = ((IData)(vlSelf->branch) ? ((0U 
                                                  == (IData)(vlSelf->funct3))
                                                  ? 1U
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlSelf->funct3))
                                                   ? 1U
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->funct3))
                                                    ? 8U
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelf->funct3))
                                                     ? 8U
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->funct3))
                                                      ? 9U
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->funct3))
                                                       ? 9U
                                                       : 0U))))))
                       : ((IData)(decoder__DOT____VdfgTmp_hbed6aa0b__0)
                           ? ((0U == (IData)(vlSelf->funct3))
                               ? (((0x33U == (IData)(vlSelf->opcode)) 
                                   & (vlSelf->inst 
                                      >> 0x1eU)) ? 1U
                                   : 0U) : ((1U == (IData)(vlSelf->funct3))
                                             ? 5U : 
                                            ((2U == (IData)(vlSelf->funct3))
                                              ? 8U : 
                                             ((3U == (IData)(vlSelf->funct3))
                                               ? 9U
                                               : ((4U 
                                                   == (IData)(vlSelf->funct3))
                                                   ? 4U
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->funct3))
                                                    ? 
                                                   ((0x40000000U 
                                                     & vlSelf->inst)
                                                     ? 7U
                                                     : 6U)
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelf->funct3))
                                                     ? 3U
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelf->funct3))
                                                      ? 2U
                                                      : 0U))))))))
                           : 0U));
    vlSelf->imm = (((IData)(vlSelf->mem_read) | ((0x13U 
                                                  == (IData)(vlSelf->opcode)) 
                                                 | (0x67U 
                                                    == (IData)(vlSelf->opcode))))
                    ? (((- (IData)((vlSelf->inst >> 0x1fU))) 
                        << 0xcU) | (vlSelf->inst >> 0x14U))
                    : ((IData)(vlSelf->mem_write) ? 
                       (((- (IData)((vlSelf->inst >> 0x1fU))) 
                         << 0xcU) | (((IData)(vlSelf->funct7) 
                                      << 5U) | (IData)(vlSelf->rd)))
                        : ((IData)(vlSelf->branch) ? 
                           (((- (IData)((vlSelf->inst 
                                         >> 0x1fU))) 
                             << 0xdU) | ((0x1000U & 
                                          (vlSelf->inst 
                                           >> 0x13U)) 
                                         | ((0x800U 
                                             & (vlSelf->inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->inst 
                                                     >> 7U))))))
                            : ((IData)(decoder__DOT____VdfgTmp_hcdfb786b__0)
                                ? (0xfffff000U & vlSelf->inst)
                                : ((0x6fU == (IData)(vlSelf->opcode))
                                    ? (((- (IData)(
                                                   (vlSelf->inst 
                                                    >> 0x1fU))) 
                                        << 0x15U) | 
                                       ((0x100000U 
                                         & (vlSelf->inst 
                                            >> 0xbU)) 
                                        | ((0xff000U 
                                            & vlSelf->inst) 
                                           | ((0x800U 
                                               & (vlSelf->inst 
                                                  >> 9U)) 
                                              | (0x7feU 
                                                 & (vlSelf->inst 
                                                    >> 0x14U))))))
                                    : 0U)))));
    decoder__DOT____VdfgTmp_hfb99b22b__0 = ((0x67U 
                                             == (IData)(vlSelf->opcode)) 
                                            | (IData)(decoder__DOT____VdfgTmp_hcdfb786b__0));
    vlSelf->reg_write = ((IData)(decoder__DOT____VdfgTmp_hbed6aa0b__0) 
                         | ((IData)(vlSelf->mem_read) 
                            | ((0x6fU == (IData)(vlSelf->opcode)) 
                               | (IData)(decoder__DOT____VdfgTmp_hfb99b22b__0))));
    vlSelf->alu_src = ((0x13U == (IData)(vlSelf->opcode)) 
                       | ((IData)(vlSelf->mem_read) 
                          | ((IData)(vlSelf->mem_write) 
                             | (IData)(decoder__DOT____VdfgTmp_hfb99b22b__0))));
}

void Vdecoder___024root___eval_ico(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vdecoder___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vdecoder___024root___eval_triggers__ico(Vdecoder___024root* vlSelf);

bool Vdecoder___024root___eval_phase__ico(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdecoder___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vdecoder___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdecoder___024root___eval_act(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_act\n"); );
}

void Vdecoder___024root___eval_nba(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_nba\n"); );
}

void Vdecoder___024root___eval_triggers__act(Vdecoder___024root* vlSelf);

bool Vdecoder___024root___eval_phase__act(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdecoder___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vdecoder___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdecoder___024root___eval_phase__nba(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdecoder___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecoder___024root___dump_triggers__ico(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecoder___024root___dump_triggers__nba(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdecoder___024root___dump_triggers__act(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG

void Vdecoder___024root___eval(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval\n"); );
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
            Vdecoder___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/decoder.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdecoder___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdecoder___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("generated_rtl/decoder.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vdecoder___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("generated_rtl/decoder.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vdecoder___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vdecoder___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdecoder___024root___eval_debug_assertions(Vdecoder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
