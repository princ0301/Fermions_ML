// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdecoder__Syms.h"


void Vdecoder___024root__trace_chg_0_sub_0(Vdecoder___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdecoder___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root__trace_chg_0\n"); );
    // Init
    Vdecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecoder___024root*>(voidSelf);
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdecoder___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vdecoder___024root__trace_chg_0_sub_0(Vdecoder___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgIData(oldp+0,(vlSelf->inst),32);
    bufp->chgCData(oldp+1,(vlSelf->opcode),7);
    bufp->chgCData(oldp+2,(vlSelf->funct3),3);
    bufp->chgCData(oldp+3,(vlSelf->funct7),7);
    bufp->chgCData(oldp+4,(vlSelf->rs1),5);
    bufp->chgCData(oldp+5,(vlSelf->rs2),5);
    bufp->chgCData(oldp+6,(vlSelf->rd),5);
    bufp->chgIData(oldp+7,(vlSelf->imm),32);
    bufp->chgBit(oldp+8,(vlSelf->reg_write));
    bufp->chgBit(oldp+9,(vlSelf->mem_read));
    bufp->chgBit(oldp+10,(vlSelf->mem_write));
    bufp->chgBit(oldp+11,(vlSelf->branch));
    bufp->chgBit(oldp+12,(vlSelf->jump));
    bufp->chgBit(oldp+13,(vlSelf->alu_src));
    bufp->chgCData(oldp+14,(vlSelf->alu_op),4);
    bufp->chgIData(oldp+15,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->inst 
                                          >> 0x14U))),32);
    bufp->chgIData(oldp+16,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (((IData)(vlSelf->funct7) 
                                           << 5U) | (IData)(vlSelf->rd)))),32);
    bufp->chgIData(oldp+17,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0xdU) | ((0x1000U 
                                           & (vlSelf->inst 
                                              >> 0x13U)) 
                                          | ((0x800U 
                                              & (vlSelf->inst 
                                                 << 4U)) 
                                             | ((0x7e0U 
                                                 & (vlSelf->inst 
                                                    >> 0x14U)) 
                                                | (0x1eU 
                                                   & (vlSelf->inst 
                                                      >> 7U))))))),32);
    bufp->chgIData(oldp+18,((0xfffff000U & vlSelf->inst)),32);
    bufp->chgIData(oldp+19,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0x15U) | ((0x100000U 
                                            & (vlSelf->inst 
                                               >> 0xbU)) 
                                           | ((0xff000U 
                                               & vlSelf->inst) 
                                              | ((0x800U 
                                                  & (vlSelf->inst 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->inst 
                                                       >> 0x14U))))))),32);
    bufp->chgBit(oldp+20,(((0x33U == (IData)(vlSelf->opcode)) 
                           & (vlSelf->inst >> 0x1eU))));
}

void Vdecoder___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecoder___024root__trace_cleanup\n"); );
    // Init
    Vdecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecoder___024root*>(voidSelf);
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
