// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_file.h for the primary calling header

#include "Vreg_file__pch.h"
#include "Vreg_file__Syms.h"
#include "Vreg_file___024root.h"

void Vreg_file___024root___ctor_var_reset(Vreg_file___024root* vlSelf);

Vreg_file___024root::Vreg_file___024root(Vreg_file__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vreg_file___024root___ctor_var_reset(this);
}

void Vreg_file___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vreg_file___024root::~Vreg_file___024root() {
}
