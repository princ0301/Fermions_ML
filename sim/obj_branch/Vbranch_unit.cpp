// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbranch_unit__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vbranch_unit::Vbranch_unit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbranch_unit__Syms(contextp(), _vcname__, this)}
    , funct3{vlSymsp->TOP.funct3}
    , is_branch{vlSymsp->TOP.is_branch}
    , branch_taken{vlSymsp->TOP.branch_taken}
    , rs1_val{vlSymsp->TOP.rs1_val}
    , rs2_val{vlSymsp->TOP.rs2_val}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbranch_unit::Vbranch_unit(const char* _vcname__)
    : Vbranch_unit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbranch_unit::~Vbranch_unit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbranch_unit___024root___eval_debug_assertions(Vbranch_unit___024root* vlSelf);
#endif  // VL_DEBUG
void Vbranch_unit___024root___eval_static(Vbranch_unit___024root* vlSelf);
void Vbranch_unit___024root___eval_initial(Vbranch_unit___024root* vlSelf);
void Vbranch_unit___024root___eval_settle(Vbranch_unit___024root* vlSelf);
void Vbranch_unit___024root___eval(Vbranch_unit___024root* vlSelf);

void Vbranch_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbranch_unit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbranch_unit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbranch_unit___024root___eval_static(&(vlSymsp->TOP));
        Vbranch_unit___024root___eval_initial(&(vlSymsp->TOP));
        Vbranch_unit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbranch_unit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbranch_unit::eventsPending() { return false; }

uint64_t Vbranch_unit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbranch_unit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbranch_unit___024root___eval_final(Vbranch_unit___024root* vlSelf);

VL_ATTR_COLD void Vbranch_unit::final() {
    Vbranch_unit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbranch_unit::hierName() const { return vlSymsp->name(); }
const char* Vbranch_unit::modelName() const { return "Vbranch_unit"; }
unsigned Vbranch_unit::threads() const { return 1; }
void Vbranch_unit::prepareClone() const { contextp()->prepareClone(); }
void Vbranch_unit::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vbranch_unit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vbranch_unit___024root__trace_decl_types(VerilatedVcd* tracep);

void Vbranch_unit___024root__trace_init_top(Vbranch_unit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbranch_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbranch_unit___024root*>(voidSelf);
    Vbranch_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vbranch_unit___024root__trace_decl_types(tracep);
    Vbranch_unit___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbranch_unit___024root__trace_register(Vbranch_unit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbranch_unit::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbranch_unit::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vbranch_unit___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
