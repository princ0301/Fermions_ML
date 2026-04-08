// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_file.h for the primary calling header

#include "Vreg_file__pch.h"
#include "Vreg_file__Syms.h"
#include "Vreg_file___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_file___024root___dump_triggers__stl(Vreg_file___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vreg_file___024root___eval_triggers__stl(Vreg_file___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vreg_file___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
