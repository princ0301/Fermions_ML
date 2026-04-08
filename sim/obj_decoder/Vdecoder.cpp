// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdecoder__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdecoder::Vdecoder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdecoder__Syms(contextp(), _vcname__, this)}
    , opcode{vlSymsp->TOP.opcode}
    , funct3{vlSymsp->TOP.funct3}
    , funct7{vlSymsp->TOP.funct7}
    , rs1{vlSymsp->TOP.rs1}
    , rs2{vlSymsp->TOP.rs2}
    , rd{vlSymsp->TOP.rd}
    , reg_write{vlSymsp->TOP.reg_write}
    , mem_read{vlSymsp->TOP.mem_read}
    , mem_write{vlSymsp->TOP.mem_write}
    , branch{vlSymsp->TOP.branch}
    , jump{vlSymsp->TOP.jump}
    , alu_src{vlSymsp->TOP.alu_src}
    , alu_op{vlSymsp->TOP.alu_op}
    , inst{vlSymsp->TOP.inst}
    , imm{vlSymsp->TOP.imm}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdecoder::Vdecoder(const char* _vcname__)
    : Vdecoder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdecoder::~Vdecoder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdecoder___024root___eval_debug_assertions(Vdecoder___024root* vlSelf);
#endif  // VL_DEBUG
void Vdecoder___024root___eval_static(Vdecoder___024root* vlSelf);
void Vdecoder___024root___eval_initial(Vdecoder___024root* vlSelf);
void Vdecoder___024root___eval_settle(Vdecoder___024root* vlSelf);
void Vdecoder___024root___eval(Vdecoder___024root* vlSelf);

void Vdecoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecoder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdecoder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdecoder___024root___eval_static(&(vlSymsp->TOP));
        Vdecoder___024root___eval_initial(&(vlSymsp->TOP));
        Vdecoder___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdecoder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdecoder::eventsPending() { return false; }

uint64_t Vdecoder::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdecoder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdecoder___024root___eval_final(Vdecoder___024root* vlSelf);

VL_ATTR_COLD void Vdecoder::final() {
    Vdecoder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdecoder::hierName() const { return vlSymsp->name(); }
const char* Vdecoder::modelName() const { return "Vdecoder"; }
unsigned Vdecoder::threads() const { return 1; }
void Vdecoder::prepareClone() const { contextp()->prepareClone(); }
void Vdecoder::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vdecoder::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdecoder___024root__trace_decl_types(VerilatedVcd* tracep);

void Vdecoder___024root__trace_init_top(Vdecoder___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdecoder___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecoder___024root*>(voidSelf);
    Vdecoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vdecoder___024root__trace_decl_types(tracep);
    Vdecoder___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdecoder___024root__trace_register(Vdecoder___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdecoder::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdecoder::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdecoder___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
