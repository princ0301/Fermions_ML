// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vreg_file__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vreg_file::Vreg_file(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vreg_file__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , we{vlSymsp->TOP.we}
    , rs1{vlSymsp->TOP.rs1}
    , rs2{vlSymsp->TOP.rs2}
    , rd{vlSymsp->TOP.rd}
    , wdata{vlSymsp->TOP.wdata}
    , rdata1{vlSymsp->TOP.rdata1}
    , rdata2{vlSymsp->TOP.rdata2}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vreg_file::Vreg_file(const char* _vcname__)
    : Vreg_file(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vreg_file::~Vreg_file() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vreg_file___024root___eval_debug_assertions(Vreg_file___024root* vlSelf);
#endif  // VL_DEBUG
void Vreg_file___024root___eval_static(Vreg_file___024root* vlSelf);
void Vreg_file___024root___eval_initial(Vreg_file___024root* vlSelf);
void Vreg_file___024root___eval_settle(Vreg_file___024root* vlSelf);
void Vreg_file___024root___eval(Vreg_file___024root* vlSelf);

void Vreg_file::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vreg_file::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vreg_file___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vreg_file___024root___eval_static(&(vlSymsp->TOP));
        Vreg_file___024root___eval_initial(&(vlSymsp->TOP));
        Vreg_file___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vreg_file___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vreg_file::eventsPending() { return false; }

uint64_t Vreg_file::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vreg_file::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vreg_file___024root___eval_final(Vreg_file___024root* vlSelf);

VL_ATTR_COLD void Vreg_file::final() {
    Vreg_file___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vreg_file::hierName() const { return vlSymsp->name(); }
const char* Vreg_file::modelName() const { return "Vreg_file"; }
unsigned Vreg_file::threads() const { return 1; }
void Vreg_file::prepareClone() const { contextp()->prepareClone(); }
void Vreg_file::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vreg_file::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vreg_file___024root__trace_decl_types(VerilatedVcd* tracep);

void Vreg_file___024root__trace_init_top(Vreg_file___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vreg_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg_file___024root*>(voidSelf);
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vreg_file___024root__trace_decl_types(tracep);
    Vreg_file___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vreg_file___024root__trace_register(Vreg_file___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vreg_file::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vreg_file::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vreg_file___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
