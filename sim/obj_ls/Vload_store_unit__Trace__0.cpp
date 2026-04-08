// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vload_store_unit__Syms.h"


void Vload_store_unit___024root__trace_chg_0_sub_0(Vload_store_unit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vload_store_unit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root__trace_chg_0\n"); );
    // Init
    Vload_store_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vload_store_unit___024root*>(voidSelf);
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vload_store_unit___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vload_store_unit___024root__trace_chg_0_sub_0(Vload_store_unit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelf->addr),32);
    bufp->chgIData(oldp+1,(vlSelf->wdata),32);
    bufp->chgCData(oldp+2,(vlSelf->funct3),3);
    bufp->chgBit(oldp+3,(vlSelf->mem_read));
    bufp->chgBit(oldp+4,(vlSelf->mem_write));
    bufp->chgIData(oldp+5,(vlSelf->rdata),32);
    bufp->chgCData(oldp+6,(vlSelf->byte_en),4);
    bufp->chgIData(oldp+7,(vlSelf->mem_addr),32);
    bufp->chgIData(oldp+8,(vlSelf->mem_wdata),32);
}

void Vload_store_unit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vload_store_unit___024root__trace_cleanup\n"); );
    // Init
    Vload_store_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vload_store_unit___024root*>(voidSelf);
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
