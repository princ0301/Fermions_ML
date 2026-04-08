// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vload_store_unit.h for the primary calling header

#ifndef VERILATED_VLOAD_STORE_UNIT___024ROOT_H_
#define VERILATED_VLOAD_STORE_UNIT___024ROOT_H_  // guard

#include "verilated.h"


class Vload_store_unit__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vload_store_unit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(funct3,2,0);
    VL_IN8(mem_read,0,0);
    VL_IN8(mem_write,0,0);
    VL_OUT8(byte_en,3,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN(addr,31,0);
    VL_IN(wdata,31,0);
    VL_OUT(rdata,31,0);
    VL_OUT(mem_addr,31,0);
    VL_OUT(mem_wdata,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vload_store_unit__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vload_store_unit___024root(Vload_store_unit__Syms* symsp, const char* v__name);
    ~Vload_store_unit___024root();
    VL_UNCOPYABLE(Vload_store_unit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
