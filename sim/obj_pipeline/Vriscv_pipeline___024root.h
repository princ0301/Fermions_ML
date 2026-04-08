// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vriscv_pipeline.h for the primary calling header

#ifndef VERILATED_VRISCV_PIPELINE___024ROOT_H_
#define VERILATED_VRISCV_PIPELINE___024ROOT_H_  // guard

#include "verilated.h"


class Vriscv_pipeline__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vriscv_pipeline___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(data_mem_we,0,0);
    VL_OUT8(data_mem_re,0,0);
    CData/*4:0*/ riscv_pipeline__DOT__id_ex_rd;
    CData/*4:0*/ riscv_pipeline__DOT__id_ex_rs1;
    CData/*4:0*/ riscv_pipeline__DOT__id_ex_rs2;
    CData/*6:0*/ riscv_pipeline__DOT__id_ex_opcode;
    CData/*4:0*/ riscv_pipeline__DOT__ex_mem_rd;
    CData/*0:0*/ riscv_pipeline__DOT__ex_mem_reg_write;
    CData/*0:0*/ riscv_pipeline__DOT__ex_mem_mem_re;
    CData/*0:0*/ riscv_pipeline__DOT__ex_mem_mem_we;
    CData/*4:0*/ riscv_pipeline__DOT__mem_wb_rd;
    CData/*0:0*/ riscv_pipeline__DOT__mem_wb_reg_write;
    CData/*0:0*/ riscv_pipeline__DOT__mem_wb_mem_to_reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(instr_mem_addr,31,0);
    VL_IN(instr_mem_data,31,0);
    VL_OUT(data_mem_addr,31,0);
    VL_OUT(data_mem_wdata,31,0);
    VL_IN(data_mem_rdata,31,0);
    IData/*31:0*/ riscv_pipeline__DOT__pc;
    IData/*31:0*/ riscv_pipeline__DOT__if_id_instr;
    IData/*31:0*/ riscv_pipeline__DOT__i;
    IData/*31:0*/ riscv_pipeline__DOT__id_ex_rs1_data;
    IData/*31:0*/ riscv_pipeline__DOT__id_ex_rs2_data;
    IData/*31:0*/ riscv_pipeline__DOT__id_ex_imm;
    IData/*31:0*/ riscv_pipeline__DOT__ex_mem_result;
    IData/*31:0*/ riscv_pipeline__DOT__ex_mem_wdata;
    IData/*31:0*/ riscv_pipeline__DOT__mem_wb_final_result;
    IData/*31:0*/ riscv_pipeline__DOT__fwd_a;
    IData/*31:0*/ riscv_pipeline__DOT__fwd_b;
    IData/*31:0*/ riscv_pipeline__DOT__mem_wb_result;
    IData/*31:0*/ riscv_pipeline__DOT__mem_wb_rdata;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> riscv_pipeline__DOT__regfile;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vriscv_pipeline__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vriscv_pipeline___024root(Vriscv_pipeline__Syms* symsp, const char* v__name);
    ~Vriscv_pipeline___024root();
    VL_UNCOPYABLE(Vriscv_pipeline___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
