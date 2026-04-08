// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vprogram_counter__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vprogram_counter::Vprogram_counter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vprogram_counter__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , stall{vlSymsp->TOP.stall}
    , branch_taken{vlSymsp->TOP.branch_taken}
    , jump_taken{vlSymsp->TOP.jump_taken}
    , branch_target{vlSymsp->TOP.branch_target}
    , jump_target{vlSymsp->TOP.jump_target}
    , pc{vlSymsp->TOP.pc}
    , next_pc{vlSymsp->TOP.next_pc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vprogram_counter::Vprogram_counter(const char* _vcname__)
    : Vprogram_counter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vprogram_counter::~Vprogram_counter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vprogram_counter___024root___eval_debug_assertions(Vprogram_counter___024root* vlSelf);
#endif  // VL_DEBUG
void Vprogram_counter___024root___eval_static(Vprogram_counter___024root* vlSelf);
void Vprogram_counter___024root___eval_initial(Vprogram_counter___024root* vlSelf);
void Vprogram_counter___024root___eval_settle(Vprogram_counter___024root* vlSelf);
void Vprogram_counter___024root___eval(Vprogram_counter___024root* vlSelf);

void Vprogram_counter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vprogram_counter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vprogram_counter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vprogram_counter___024root___eval_static(&(vlSymsp->TOP));
        Vprogram_counter___024root___eval_initial(&(vlSymsp->TOP));
        Vprogram_counter___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vprogram_counter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vprogram_counter::eventsPending() { return false; }

uint64_t Vprogram_counter::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vprogram_counter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vprogram_counter___024root___eval_final(Vprogram_counter___024root* vlSelf);

VL_ATTR_COLD void Vprogram_counter::final() {
    Vprogram_counter___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vprogram_counter::hierName() const { return vlSymsp->name(); }
const char* Vprogram_counter::modelName() const { return "Vprogram_counter"; }
unsigned Vprogram_counter::threads() const { return 1; }
void Vprogram_counter::prepareClone() const { contextp()->prepareClone(); }
void Vprogram_counter::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vprogram_counter::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vprogram_counter___024root__trace_decl_types(VerilatedVcd* tracep);

void Vprogram_counter___024root__trace_init_top(Vprogram_counter___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vprogram_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprogram_counter___024root*>(voidSelf);
    Vprogram_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vprogram_counter___024root__trace_decl_types(tracep);
    Vprogram_counter___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vprogram_counter___024root__trace_register(Vprogram_counter___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vprogram_counter::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vprogram_counter::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vprogram_counter___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
