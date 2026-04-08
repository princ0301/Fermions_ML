// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vload_store_unit__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vload_store_unit::Vload_store_unit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vload_store_unit__Syms(contextp(), _vcname__, this)}
    , funct3{vlSymsp->TOP.funct3}
    , mem_read{vlSymsp->TOP.mem_read}
    , mem_write{vlSymsp->TOP.mem_write}
    , byte_en{vlSymsp->TOP.byte_en}
    , addr{vlSymsp->TOP.addr}
    , wdata{vlSymsp->TOP.wdata}
    , rdata{vlSymsp->TOP.rdata}
    , mem_addr{vlSymsp->TOP.mem_addr}
    , mem_wdata{vlSymsp->TOP.mem_wdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vload_store_unit::Vload_store_unit(const char* _vcname__)
    : Vload_store_unit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vload_store_unit::~Vload_store_unit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vload_store_unit___024root___eval_debug_assertions(Vload_store_unit___024root* vlSelf);
#endif  // VL_DEBUG
void Vload_store_unit___024root___eval_static(Vload_store_unit___024root* vlSelf);
void Vload_store_unit___024root___eval_initial(Vload_store_unit___024root* vlSelf);
void Vload_store_unit___024root___eval_settle(Vload_store_unit___024root* vlSelf);
void Vload_store_unit___024root___eval(Vload_store_unit___024root* vlSelf);

void Vload_store_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vload_store_unit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vload_store_unit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vload_store_unit___024root___eval_static(&(vlSymsp->TOP));
        Vload_store_unit___024root___eval_initial(&(vlSymsp->TOP));
        Vload_store_unit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vload_store_unit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vload_store_unit::eventsPending() { return false; }

uint64_t Vload_store_unit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vload_store_unit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vload_store_unit___024root___eval_final(Vload_store_unit___024root* vlSelf);

VL_ATTR_COLD void Vload_store_unit::final() {
    Vload_store_unit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vload_store_unit::hierName() const { return vlSymsp->name(); }
const char* Vload_store_unit::modelName() const { return "Vload_store_unit"; }
unsigned Vload_store_unit::threads() const { return 1; }
void Vload_store_unit::prepareClone() const { contextp()->prepareClone(); }
void Vload_store_unit::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vload_store_unit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vload_store_unit___024root__trace_decl_types(VerilatedVcd* tracep);

void Vload_store_unit___024root__trace_init_top(Vload_store_unit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vload_store_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vload_store_unit___024root*>(voidSelf);
    Vload_store_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vload_store_unit___024root__trace_decl_types(tracep);
    Vload_store_unit___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vload_store_unit___024root__trace_register(Vload_store_unit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vload_store_unit::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vload_store_unit::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vload_store_unit___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
