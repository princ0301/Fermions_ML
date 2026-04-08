// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vload_store_unit.h for the primary calling header

#include "Vload_store_unit__pch.h"
#include "Vload_store_unit__Syms.h"
#include "Vload_store_unit___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__ico(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG

void Vload_store_unit___024root___eval_triggers__ico(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vload_store_unit___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vload_store_unit___024root___dump_triggers__act(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG

void Vload_store_unit___024root___eval_triggers__act(Vload_store_unit___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vload_store_unit___024root___dump_triggers__act(vlSelf);
    }
#endif
}
