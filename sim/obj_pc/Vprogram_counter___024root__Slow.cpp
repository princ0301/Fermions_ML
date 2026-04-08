// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprogram_counter.h for the primary calling header

#include "Vprogram_counter__pch.h"
#include "Vprogram_counter__Syms.h"
#include "Vprogram_counter___024root.h"

void Vprogram_counter___024root___ctor_var_reset(Vprogram_counter___024root* vlSelf);

Vprogram_counter___024root::Vprogram_counter___024root(Vprogram_counter__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vprogram_counter___024root___ctor_var_reset(this);
}

void Vprogram_counter___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vprogram_counter___024root::~Vprogram_counter___024root() {
}
