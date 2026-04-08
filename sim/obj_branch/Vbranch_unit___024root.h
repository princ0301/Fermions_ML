// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbranch_unit.h for the primary calling header

#ifndef VERILATED_VBRANCH_UNIT___024ROOT_H_
#define VERILATED_VBRANCH_UNIT___024ROOT_H_  // guard

#include "verilated.h"


class Vbranch_unit__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbranch_unit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(funct3,2,0);
    VL_IN8(is_branch,0,0);
    VL_OUT8(branch_taken,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN(rs1_val,31,0);
    VL_IN(rs2_val,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbranch_unit__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbranch_unit___024root(Vbranch_unit__Syms* symsp, const char* v__name);
    ~Vbranch_unit___024root();
    VL_UNCOPYABLE(Vbranch_unit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
