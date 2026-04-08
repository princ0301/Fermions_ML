// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_pipeline.h for the primary calling header

#include "Vriscv_pipeline__pch.h"
#include "Vriscv_pipeline__Syms.h"
#include "Vriscv_pipeline___024root.h"

void Vriscv_pipeline___024root___ctor_var_reset(Vriscv_pipeline___024root* vlSelf);

Vriscv_pipeline___024root::Vriscv_pipeline___024root(Vriscv_pipeline__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vriscv_pipeline___024root___ctor_var_reset(this);
}

void Vriscv_pipeline___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vriscv_pipeline___024root::~Vriscv_pipeline___024root() {
}
