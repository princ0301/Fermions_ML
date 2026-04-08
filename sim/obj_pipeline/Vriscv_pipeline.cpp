// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vriscv_pipeline__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vriscv_pipeline::Vriscv_pipeline(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vriscv_pipeline__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , data_mem_we{vlSymsp->TOP.data_mem_we}
    , data_mem_re{vlSymsp->TOP.data_mem_re}
    , instr_mem_addr{vlSymsp->TOP.instr_mem_addr}
    , instr_mem_data{vlSymsp->TOP.instr_mem_data}
    , data_mem_addr{vlSymsp->TOP.data_mem_addr}
    , data_mem_wdata{vlSymsp->TOP.data_mem_wdata}
    , data_mem_rdata{vlSymsp->TOP.data_mem_rdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vriscv_pipeline::Vriscv_pipeline(const char* _vcname__)
    : Vriscv_pipeline(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vriscv_pipeline::~Vriscv_pipeline() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vriscv_pipeline___024root___eval_debug_assertions(Vriscv_pipeline___024root* vlSelf);
#endif  // VL_DEBUG
void Vriscv_pipeline___024root___eval_static(Vriscv_pipeline___024root* vlSelf);
void Vriscv_pipeline___024root___eval_initial(Vriscv_pipeline___024root* vlSelf);
void Vriscv_pipeline___024root___eval_settle(Vriscv_pipeline___024root* vlSelf);
void Vriscv_pipeline___024root___eval(Vriscv_pipeline___024root* vlSelf);

void Vriscv_pipeline::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_pipeline::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vriscv_pipeline___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vriscv_pipeline___024root___eval_static(&(vlSymsp->TOP));
        Vriscv_pipeline___024root___eval_initial(&(vlSymsp->TOP));
        Vriscv_pipeline___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vriscv_pipeline___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vriscv_pipeline::eventsPending() { return false; }

uint64_t Vriscv_pipeline::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vriscv_pipeline::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vriscv_pipeline___024root___eval_final(Vriscv_pipeline___024root* vlSelf);

VL_ATTR_COLD void Vriscv_pipeline::final() {
    Vriscv_pipeline___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vriscv_pipeline::hierName() const { return vlSymsp->name(); }
const char* Vriscv_pipeline::modelName() const { return "Vriscv_pipeline"; }
unsigned Vriscv_pipeline::threads() const { return 1; }
void Vriscv_pipeline::prepareClone() const { contextp()->prepareClone(); }
void Vriscv_pipeline::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vriscv_pipeline::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vriscv_pipeline___024root__trace_decl_types(VerilatedVcd* tracep);

void Vriscv_pipeline___024root__trace_init_top(Vriscv_pipeline___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vriscv_pipeline___024root*>(voidSelf);
    Vriscv_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vriscv_pipeline___024root__trace_decl_types(tracep);
    Vriscv_pipeline___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vriscv_pipeline___024root__trace_register(Vriscv_pipeline___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vriscv_pipeline::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vriscv_pipeline::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vriscv_pipeline___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
