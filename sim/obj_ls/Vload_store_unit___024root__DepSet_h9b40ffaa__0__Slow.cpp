// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vload_store_unit.h for the primary calling header

#include "Vload_store_unit__pch.h"
#include "Vload_store_unit__Syms.h"
#include "Vload_store_unit___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__stl(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vload_store_unit___024root___eval_triggers__stl(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vload_store_unit___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
