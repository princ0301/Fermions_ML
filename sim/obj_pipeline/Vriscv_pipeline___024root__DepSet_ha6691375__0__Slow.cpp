// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_pipeline.h for the primary calling header

#include "Vriscv_pipeline__pch.h"
#include "Vriscv_pipeline__Syms.h"
#include "Vriscv_pipeline___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vriscv_pipeline___024root___dump_triggers__stl(Vriscv_pipeline___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vriscv_pipeline___024root___eval_triggers__stl(Vriscv_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_pipeline___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vriscv_pipeline___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
