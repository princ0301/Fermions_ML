// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_pipeline.h for the primary calling header

#include "Vriscv_pipeline__pch.h"
#include "Vriscv_pipeline___024root.h"

void Vriscv_pipeline___024root___eval_act(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vriscv_pipeline___024root___nba_sequent__TOP__0(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__riscv_pipeline__DOT__regfile__v0;
    __Vdlyvdim0__riscv_pipeline__DOT__regfile__v0 = 0;
    IData/*31:0*/ __Vdlyvval__riscv_pipeline__DOT__regfile__v0;
    __Vdlyvval__riscv_pipeline__DOT__regfile__v0 = 0;
    CData/*0:0*/ __Vdlyvset__riscv_pipeline__DOT__regfile__v0;
    __Vdlyvset__riscv_pipeline__DOT__regfile__v0 = 0;
    // Body
    __Vdlyvset__riscv_pipeline__DOT__regfile__v0 = 0U;
    if ((((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->riscv_pipeline__DOT__mem_wb_reg_write)) 
         & (0U != (IData)(vlSelf->riscv_pipeline__DOT__mem_wb_rd)))) {
        __Vdlyvval__riscv_pipeline__DOT__regfile__v0 
            = vlSelf->riscv_pipeline__DOT__mem_wb_final_result;
        __Vdlyvset__riscv_pipeline__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__riscv_pipeline__DOT__regfile__v0 
            = vlSelf->riscv_pipeline__DOT__mem_wb_rd;
    }
    vlSelf->riscv_pipeline__DOT__ex_mem_mem_we = ((1U 
                                                   & (~ (IData)(vlSelf->rst))) 
                                                  && (0x23U 
                                                      == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode)));
    vlSelf->riscv_pipeline__DOT__mem_wb_mem_to_reg 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->riscv_pipeline__DOT__ex_mem_mem_re));
    if (vlSelf->rst) {
        vlSelf->riscv_pipeline__DOT__pc = 0U;
        vlSelf->riscv_pipeline__DOT__mem_wb_rdata = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_rs2 = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_rs1 = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_rs2_data = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_rs1_data = 0U;
    } else {
        vlSelf->riscv_pipeline__DOT__pc = ((IData)(4U) 
                                           + vlSelf->riscv_pipeline__DOT__pc);
        vlSelf->riscv_pipeline__DOT__mem_wb_rdata = vlSelf->data_mem_rdata;
        vlSelf->riscv_pipeline__DOT__id_ex_rs2 = (0x1fU 
                                                  & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                     >> 0x14U));
        vlSelf->riscv_pipeline__DOT__id_ex_rs1 = (0x1fU 
                                                  & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                     >> 0xfU));
        vlSelf->riscv_pipeline__DOT__id_ex_rs2_data 
            = vlSelf->riscv_pipeline__DOT__regfile[
            (0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                      >> 0x14U))];
        vlSelf->riscv_pipeline__DOT__id_ex_rs1_data 
            = vlSelf->riscv_pipeline__DOT__regfile[
            (0x1fU & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                      >> 0xfU))];
    }
    if (__Vdlyvset__riscv_pipeline__DOT__regfile__v0) {
        vlSelf->riscv_pipeline__DOT__regfile[__Vdlyvdim0__riscv_pipeline__DOT__regfile__v0] 
            = __Vdlyvval__riscv_pipeline__DOT__regfile__v0;
    }
    vlSelf->instr_mem_addr = vlSelf->riscv_pipeline__DOT__pc;
    vlSelf->riscv_pipeline__DOT__mem_wb_reg_write = 
        ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->riscv_pipeline__DOT__ex_mem_reg_write));
    vlSelf->data_mem_we = vlSelf->riscv_pipeline__DOT__ex_mem_mem_we;
    if (vlSelf->rst) {
        vlSelf->riscv_pipeline__DOT__ex_mem_wdata = 0U;
    } else if ((1U & (~ ((IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode) 
                         >> 6U)))) {
        if ((0x20U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))) {
            if ((1U & (~ ((IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))) {
                            if ((1U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))) {
                                vlSelf->riscv_pipeline__DOT__ex_mem_wdata 
                                    = vlSelf->riscv_pipeline__DOT__fwd_b;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->data_mem_wdata = vlSelf->riscv_pipeline__DOT__ex_mem_wdata;
    vlSelf->riscv_pipeline__DOT__ex_mem_mem_re = ((1U 
                                                   & (~ (IData)(vlSelf->rst))) 
                                                  && (3U 
                                                      == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode)));
    vlSelf->riscv_pipeline__DOT__mem_wb_result = ((IData)(vlSelf->rst)
                                                   ? 0U
                                                   : vlSelf->riscv_pipeline__DOT__ex_mem_result);
    vlSelf->riscv_pipeline__DOT__mem_wb_final_result 
        = ((IData)(vlSelf->riscv_pipeline__DOT__mem_wb_mem_to_reg)
            ? vlSelf->riscv_pipeline__DOT__mem_wb_rdata
            : vlSelf->riscv_pipeline__DOT__mem_wb_result);
    vlSelf->riscv_pipeline__DOT__ex_mem_reg_write = 
        ((1U & (~ (IData)(vlSelf->rst))) && (((0x13U 
                                               == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode)) 
                                              | (0x33U 
                                                 == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))) 
                                             | (3U 
                                                == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))));
    if (vlSelf->rst) {
        vlSelf->riscv_pipeline__DOT__mem_wb_rd = 0U;
        vlSelf->riscv_pipeline__DOT__ex_mem_result = 0U;
        vlSelf->riscv_pipeline__DOT__ex_mem_rd = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_imm = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_rd = 0U;
        vlSelf->riscv_pipeline__DOT__id_ex_opcode = 0x13U;
        vlSelf->riscv_pipeline__DOT__if_id_instr = 0x13U;
    } else {
        vlSelf->riscv_pipeline__DOT__mem_wb_rd = vlSelf->riscv_pipeline__DOT__ex_mem_rd;
        vlSelf->riscv_pipeline__DOT__ex_mem_result 
            = ((0x40U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                ? 0U : ((0x20U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                         ? ((0x10U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                             ? ((8U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                 ? 0U : ((4U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                          ? 0U : ((2U 
                                                   & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                    ? 
                                                   (vlSelf->riscv_pipeline__DOT__fwd_a 
                                                    + vlSelf->riscv_pipeline__DOT__fwd_b)
                                                    : 0U)
                                                   : 0U)))
                             : ((8U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                 ? 0U : ((4U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                          ? 0U : ((2U 
                                                   & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                    ? 
                                                   (vlSelf->riscv_pipeline__DOT__fwd_a 
                                                    + vlSelf->riscv_pipeline__DOT__id_ex_imm)
                                                    : 0U)
                                                   : 0U))))
                         : ((0x10U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                             ? ((8U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                 ? 0U : ((4U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                          ? 0U : ((2U 
                                                   & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                    ? 
                                                   (vlSelf->riscv_pipeline__DOT__fwd_a 
                                                    + vlSelf->riscv_pipeline__DOT__id_ex_imm)
                                                    : 0U)
                                                   : 0U)))
                             : ((8U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                 ? 0U : ((4U & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                          ? 0U : ((2U 
                                                   & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->riscv_pipeline__DOT__id_ex_opcode))
                                                    ? 
                                                   (vlSelf->riscv_pipeline__DOT__fwd_a 
                                                    + vlSelf->riscv_pipeline__DOT__id_ex_imm)
                                                    : 0U)
                                                   : 0U))))));
        vlSelf->riscv_pipeline__DOT__ex_mem_rd = vlSelf->riscv_pipeline__DOT__id_ex_rd;
        vlSelf->riscv_pipeline__DOT__id_ex_imm = ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->riscv_pipeline__DOT__if_id_instr))
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                            >> 7U))))
                                                   : 
                                                  (((- (IData)(
                                                               (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                      >> 0x14U)));
        vlSelf->riscv_pipeline__DOT__id_ex_rd = (0x1fU 
                                                 & (vlSelf->riscv_pipeline__DOT__if_id_instr 
                                                    >> 7U));
        vlSelf->riscv_pipeline__DOT__id_ex_opcode = 
            (0x7fU & vlSelf->riscv_pipeline__DOT__if_id_instr);
        vlSelf->riscv_pipeline__DOT__if_id_instr = vlSelf->instr_mem_data;
    }
    vlSelf->data_mem_re = vlSelf->riscv_pipeline__DOT__ex_mem_mem_re;
    vlSelf->data_mem_addr = vlSelf->riscv_pipeline__DOT__ex_mem_result;
    vlSelf->riscv_pipeline__DOT__fwd_a = (((IData)(vlSelf->riscv_pipeline__DOT__ex_mem_reg_write) 
                                           & (((IData)(vlSelf->riscv_pipeline__DOT__ex_mem_rd) 
                                               == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_rs1)) 
                                              & (0U 
                                                 != (IData)(vlSelf->riscv_pipeline__DOT__ex_mem_rd))))
                                           ? vlSelf->riscv_pipeline__DOT__ex_mem_result
                                           : (((IData)(vlSelf->riscv_pipeline__DOT__mem_wb_reg_write) 
                                               & (((IData)(vlSelf->riscv_pipeline__DOT__id_ex_rs1) 
                                                   == (IData)(vlSelf->riscv_pipeline__DOT__mem_wb_rd)) 
                                                  & (0U 
                                                     != (IData)(vlSelf->riscv_pipeline__DOT__mem_wb_rd))))
                                               ? vlSelf->riscv_pipeline__DOT__mem_wb_final_result
                                               : vlSelf->riscv_pipeline__DOT__id_ex_rs1_data));
    vlSelf->riscv_pipeline__DOT__fwd_b = (((IData)(vlSelf->riscv_pipeline__DOT__ex_mem_reg_write) 
                                           & (((IData)(vlSelf->riscv_pipeline__DOT__ex_mem_rd) 
                                               == (IData)(vlSelf->riscv_pipeline__DOT__id_ex_rs2)) 
                                              & (0U 
                                                 != (IData)(vlSelf->riscv_pipeline__DOT__ex_mem_rd))))
                                           ? vlSelf->riscv_pipeline__DOT__ex_mem_result
                                           : (((IData)(vlSelf->riscv_pipeline__DOT__mem_wb_reg_write) 
                                               & (((IData)(vlSelf->riscv_pipeline__DOT__id_ex_rs2) 
                                                   == (IData)(vlSelf->riscv_pipeline__DOT__mem_wb_rd)) 
                                                  & (0U 
                                                     != (IData)(vlSelf->riscv_pipeline__DOT__mem_wb_rd))))
                                               ? vlSelf->riscv_pipeline__DOT__mem_wb_final_result
                                               : vlSelf->riscv_pipeline__DOT__id_ex_rs2_data));
}

void Vriscv_pipeline___024root___eval_nba(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vriscv_pipeline___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vriscv_pipeline___024root___eval_triggers__act(Vriscv_pipeline___024root* vlSelf);

bool Vriscv_pipeline___024root___eval_phase__act(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vriscv_pipeline___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vriscv_pipeline___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vriscv_pipeline___024root___eval_phase__nba(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vriscv_pipeline___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__nba(Vriscv_pipeline___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__act(Vriscv_pipeline___024root* vlSelf);
#endif  // VL_DEBUG

void Vriscv_pipeline___024root___eval(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vriscv_pipeline___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../generated_rtl/pipeline_top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vriscv_pipeline___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../generated_rtl/pipeline_top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vriscv_pipeline___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vriscv_pipeline___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vriscv_pipeline___024root___eval_debug_assertions(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
