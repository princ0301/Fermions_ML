// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_pipeline.h for the primary calling header

#include "Vriscv_pipeline__pch.h"
#include "Vriscv_pipeline___024root.h"

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_static(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_initial__TOP(Vriscv_pipeline___024root* vlSelf);

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_initial(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_initial\n"); );
    // Body
    Vriscv_pipeline___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_initial__TOP(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->riscv_pipeline__DOT__regfile[0U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[1U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[2U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[3U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[4U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[5U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[6U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[7U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[8U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[9U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0xaU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0xbU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0xcU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0xdU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0xeU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0xfU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x10U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x11U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x12U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x13U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x14U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x15U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x16U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x17U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x18U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x19U] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x1aU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x1bU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x1cU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x1dU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x1eU] = 0U;
    vlSelf->riscv_pipeline__DOT__regfile[0x1fU] = 0U;
    vlSelf->riscv_pipeline__DOT__i = 0x20U;
}

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_final(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__stl(Vriscv_pipeline___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vriscv_pipeline___024root___eval_phase__stl(Vriscv_pipeline___024root* vlSelf);

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_settle(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_settle\n"); );
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
            Vriscv_pipeline___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../generated_rtl/pipeline_top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vriscv_pipeline___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__stl(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vriscv_pipeline___024root___stl_sequent__TOP__0(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->data_mem_we = vlSelf->riscv_pipeline__DOT__ex_mem_mem_we;
    vlSelf->data_mem_re = vlSelf->riscv_pipeline__DOT__ex_mem_mem_re;
    vlSelf->data_mem_addr = vlSelf->riscv_pipeline__DOT__ex_mem_result;
    vlSelf->data_mem_wdata = vlSelf->riscv_pipeline__DOT__ex_mem_wdata;
    vlSelf->instr_mem_addr = vlSelf->riscv_pipeline__DOT__pc;
    vlSelf->riscv_pipeline__DOT__mem_wb_final_result 
        = ((IData)(vlSelf->riscv_pipeline__DOT__mem_wb_mem_to_reg)
            ? vlSelf->riscv_pipeline__DOT__mem_wb_rdata
            : vlSelf->riscv_pipeline__DOT__mem_wb_result);
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

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_stl(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vriscv_pipeline___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_triggers__stl(Vriscv_pipeline___024root* vlSelf);

VL_ATTR_COLD bool Vriscv_pipeline___024root___eval_phase__stl(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vriscv_pipeline___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vriscv_pipeline___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__act(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__nba(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vriscv_pipeline___024root___ctor_var_reset(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->instr_mem_addr = VL_RAND_RESET_I(32);
    vlSelf->instr_mem_data = VL_RAND_RESET_I(32);
    vlSelf->data_mem_we = VL_RAND_RESET_I(1);
    vlSelf->data_mem_re = VL_RAND_RESET_I(1);
    vlSelf->data_mem_addr = VL_RAND_RESET_I(32);
    vlSelf->data_mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->data_mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__if_id_instr = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->riscv_pipeline__DOT__regfile[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->riscv_pipeline__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__id_ex_rs1_data = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__id_ex_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__id_ex_imm = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__id_ex_rd = VL_RAND_RESET_I(5);
    vlSelf->riscv_pipeline__DOT__id_ex_rs1 = VL_RAND_RESET_I(5);
    vlSelf->riscv_pipeline__DOT__id_ex_rs2 = VL_RAND_RESET_I(5);
    vlSelf->riscv_pipeline__DOT__id_ex_opcode = VL_RAND_RESET_I(7);
    vlSelf->riscv_pipeline__DOT__ex_mem_result = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__ex_mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__ex_mem_rd = VL_RAND_RESET_I(5);
    vlSelf->riscv_pipeline__DOT__ex_mem_reg_write = VL_RAND_RESET_I(1);
    vlSelf->riscv_pipeline__DOT__ex_mem_mem_re = VL_RAND_RESET_I(1);
    vlSelf->riscv_pipeline__DOT__ex_mem_mem_we = VL_RAND_RESET_I(1);
    vlSelf->riscv_pipeline__DOT__mem_wb_final_result = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__fwd_a = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__fwd_b = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__mem_wb_result = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__mem_wb_rdata = VL_RAND_RESET_I(32);
    vlSelf->riscv_pipeline__DOT__mem_wb_rd = VL_RAND_RESET_I(5);
    vlSelf->riscv_pipeline__DOT__mem_wb_reg_write = VL_RAND_RESET_I(1);
    vlSelf->riscv_pipeline__DOT__mem_wb_mem_to_reg = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
