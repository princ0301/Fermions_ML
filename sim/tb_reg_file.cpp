#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vreg_file.h"
#include <iostream>

int passed = 0, failed = 0;
vluint64_t sim_time = 0;

void tick(Vreg_file* dut, VerilatedVcdC* tfp) {
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
    Vreg_file* dut = new Vreg_file;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave_regfile.vcd");

    std::cout << "=== Register File Tests ===" << std::endl;

    // Reset
    dut->rst = 1; dut->we = 0; dut->clk = 0;
    dut->rs1 = 0; dut->rs2 = 0; dut->rd = 0; dut->wdata = 0;
    tick(dut, tfp);
    dut->rst = 0;

    // Test 1: x0 always reads 0
    dut->we = 1; dut->rd = 0; dut->wdata = 0xDEADBEEF;
    tick(dut, tfp);
    dut->we = 0; dut->rs1 = 0;
    dut->eval();
    check("x0 hardwired to 0", dut->rdata1, 0);

    // Test 2: Write and read back x1
    dut->we = 1; dut->rd = 1; dut->wdata = 0xABCD1234;
    tick(dut, tfp);
    dut->we = 0; dut->rs1 = 1;
    dut->eval();
    check("Write/read x1=0xABCD1234", dut->rdata1, 0xABCD1234);

    // Test 3: Write x2, read both ports simultaneously
    dut->we = 1; dut->rd = 2; dut->wdata = 0x12345678;
    tick(dut, tfp);
    dut->we = 0; dut->rs1 = 1; dut->rs2 = 2;
    dut->eval();
    check("Dual read: x1 port", dut->rdata1, 0xABCD1234);
    check("Dual read: x2 port", dut->rdata2, 0x12345678);

    // Test 4: Write x31 (last register)
    dut->we = 1; dut->rd = 31; dut->wdata = 0xFFFFFFFF;
    tick(dut, tfp);
    dut->we = 0; dut->rs1 = 31;
    dut->eval();
    check("Write/read x31=0xFFFFFFFF", dut->rdata1, 0xFFFFFFFF);

    // Test 5: No write when we=0
    dut->we = 0; dut->rd = 1; dut->wdata = 0x00000000;
    tick(dut, tfp);
    dut->rs1 = 1; dut->eval();
    check("No write when we=0", dut->rdata1, 0xABCD1234);

    std::cout << "\nResults: " << passed << " passed, " << failed << " failed" << std::endl;
    tfp->close();
    delete dut;
    return failed > 0 ? 1 : 0;
}