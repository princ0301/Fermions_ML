// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecoder.h for the primary calling header

#include "Vdecoder__pch.h"
#include "Vdecoder__Syms.h"
#include "Vdecoder___024root.h"

void Vdecoder___024root___ctor_var_reset(Vdecoder___024root* vlSelf);

Vdecoder___024root::Vdecoder___024root(Vdecoder__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdecoder___024root___ctor_var_reset(this);
}

void Vdecoder___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdecoder___024root::~Vdecoder___024root() {
}
