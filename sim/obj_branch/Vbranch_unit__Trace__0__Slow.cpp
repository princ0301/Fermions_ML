// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbranch_unit__Syms.h"


VL_ATTR_COLD void Vbranch_unit___024root__trace_init_sub__TOP__0(Vbranch_unit___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,0,"rs1_val",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rs2_val",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"is_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"branch_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("branch_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"rs1_val",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rs2_val",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"is_branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"branch_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbranch_unit___024root__trace_init_top(Vbranch_unit___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root__trace_init_top\n"); );
    // Body
    Vbranch_unit___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vbranch_unit___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vbranch_unit___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbranch_unit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbranch_unit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vbranch_unit___024root__trace_register(Vbranch_unit___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vbranch_unit___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vbranch_unit___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vbranch_unit___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vbranch_unit___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vbranch_unit___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root__trace_const_0\n"); );
    // Init
    Vbranch_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbranch_unit___024root*>(voidSelf);
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vbranch_unit___024root__trace_full_0_sub_0(Vbranch_unit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vbranch_unit___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root__trace_full_0\n"); );
    // Init
    Vbranch_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbranch_unit___024root*>(voidSelf);
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vbranch_unit___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vbranch_unit___024root__trace_full_0_sub_0(Vbranch_unit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbranch_unit___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->rs1_val),32);
    bufp->fullIData(oldp+2,(vlSelf->rs2_val),32);
    bufp->fullCData(oldp+3,(vlSelf->funct3),3);
    bufp->fullBit(oldp+4,(vlSelf->is_branch));
    bufp->fullBit(oldp+5,(vlSelf->branch_taken));
}
