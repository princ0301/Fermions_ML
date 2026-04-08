// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbranch_unit.h for the primary calling header

#include "Vbranch_unit__pch.h"
#include "Vbranch_unit__Syms.h"
#include "Vbranch_unit___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbranch_unit___024root___dump_triggers__stl(Vbranch_unit___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbranch_unit___024root___eval_triggers__stl(Vbranch_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbranch_unit___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
