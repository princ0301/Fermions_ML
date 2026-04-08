// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vprogram_counter.h for the primary calling header

#ifndef VERILATED_VPROGRAM_COUNTER___024ROOT_H_
#define VERILATED_VPROGRAM_COUNTER___024ROOT_H_  // guard

#include "verilated.h"


class Vprogram_counter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vprogram_counter___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(stall,0,0);
    VL_IN8(branch_taken,0,0);
    VL_IN8(jump_taken,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(branch_target,31,0);
    VL_IN(jump_target,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(next_pc,31,0);
    IData/*31:0*/ program_counter__DOT__pc_reg;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vprogram_counter__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vprogram_counter___024root(Vprogram_counter__Syms* symsp, const char* v__name);
    ~Vprogram_counter___024root();
    VL_UNCOPYABLE(Vprogram_counter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
