#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vprogram_counter.h"
#include <iostream>

int passed = 0, failed = 0;
vluint64_t sim_time = 0;

void tick(Vprogram_counter* dut, VerilatedVcdC* tfp) {
    dut->clk = 0; dut->eval(); tfp->dump(sim_time++);
    dut->clk = 1; dut->eval(); tfp->dump(sim_time++);
}

void check(const char* test, uint32_t got, uint32_t expected) {
    if (got == expected) {
        std::cout << "  PASS: " << test << std::endl;
        passed++;
    } else {
        std::cout << "  FAIL: " << test
                  << " got=0x" << std::hex << got
                  << " expected=0x" << expected << std::endl;
        failed++;
    }
}

int main() {
    Vprogram_counter* dut = new Vprogram_counter;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave_pc.vcd");

    std::cout << "=== Program Counter Tests ===" << std::endl;

    // Reset
    dut->rst = 1; dut->stall = 0;
    dut->branch_taken = 0; dut->branch_target = 0;
    dut->jump_taken = 0;   dut->jump_target = 0;
    tick(dut, tfp);
    dut->rst = 0;
    check("PC resets to 0", dut->pc, 0);

    // Sequential increment
    tick(dut, tfp);
    check("PC increments to 4", dut->pc, 4);

    tick(dut, tfp);
    check("PC increments to 8", dut->pc, 8);

    // Branch taken
    dut->branch_taken = 1; dut->branch_target = 0x100;
    tick(dut, tfp);
    dut->branch_taken = 0;
    check("Branch to 0x100", dut->pc, 0x100);

    // Sequential after branch
    tick(dut, tfp);
    check("Sequential after branch: 0x104", dut->pc, 0x104);

    // Jump taken
    dut->jump_taken = 1; dut->jump_target = 0x200;
    tick(dut, tfp);
    dut->jump_taken = 0;
    check("Jump to 0x200", dut->pc, 0x200);

    // Stall
    tick(dut, tfp);
    check("After jump: 0x204", dut->pc, 0x204);
    dut->stall = 1;
    tick(dut, tfp);
    check("Stall: PC holds at 0x204", dut->pc, 0x204);
    dut->stall = 0;

    // Resume after stall
    tick(dut, tfp);
    check("Resume after stall: 0x208", dut->pc, 0x208);

    std::cout << "\nResults: " << passed << " passed, " << failed << " failed" << std::endl;
    tfp->close();
    delete dut;
    return failed > 0 ? 1 : 0;
}