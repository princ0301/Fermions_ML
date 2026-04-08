// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vriscv_pipeline__pch.h"
#include "Vriscv_pipeline.h"
#include "Vriscv_pipeline___024root.h"

// FUNCTIONS
Vriscv_pipeline__Syms::~Vriscv_pipeline__Syms()
{
}

Vriscv_pipeline__Syms::Vriscv_pipeline__Syms(VerilatedContext* contextp, const char* namep, Vriscv_pipeline* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(30);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
