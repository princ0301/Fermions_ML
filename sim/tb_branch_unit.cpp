#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vbranch_unit.h"
#include <iostream>

int passed = 0, failed = 0;
vluint64_t sim_time = 0;

void check(const char* test, uint32_t got, uint32_t expected) {
    if (got == expected) {
        std::cout << "  PASS: " << test << std::endl;
        passed++;
    } else {
        std::cout << "  FAIL: " << test
                  << " got=" << got
                  << " expected=" << expected << std::endl;
        failed++;
    }
}

int main() {
    Vbranch_unit* dut = new Vbranch_unit;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave_branch.vcd");

    std::cout << "=== Branch Unit Tests ===" << std::endl;

    dut->is_branch = 1;

    // BEQ (funct3=000)
    dut->funct3 = 0b000;
    dut->rs1_val = 5; dut->rs2_val = 5; dut->eval(); tfp->dump(sim_time++);
    check("BEQ: 5==5 taken", dut->branch_taken, 1);

    dut->rs1_val = 5; dut->rs2_val = 6; dut->eval(); tfp->dump(sim_time++);
    check("BEQ: 5==6 not taken", dut->branch_taken, 0);

    // BNE (funct3=001)
    dut->funct3 = 0b001;
    dut->rs1_val = 5; dut->rs2_val = 6; dut->eval(); tfp->dump(sim_time++);
    check("BNE: 5!=6 taken", dut->branch_taken, 1);

    dut->rs1_val = 5; dut->rs2_val = 5; dut->eval(); tfp->dump(sim_time++);
    check("BNE: 5!=5 not taken", dut->branch_taken, 0);

    // BLT signed (funct3=100)
    dut->funct3 = 0b100;
    dut->rs1_val = 0xFFFFFFFF; dut->rs2_val = 1; dut->eval(); tfp->dump(sim_time++);
    check("BLT: -1 < 1 taken", dut->branch_taken, 1);

    dut->rs1_val = 1; dut->rs2_val = 0xFFFFFFFF; dut->eval(); tfp->dump(sim_time++);
    check("BLT: 1 < -1 not taken", dut->branch_taken, 0);

    // BGE signed (funct3=101)
    dut->funct3 = 0b101;
    dut->rs1_val = 1; dut->rs2_val = 0xFFFFFFFF; dut->eval(); tfp->dump(sim_time++);
    check("BGE: 1 >= -1 taken", dut->branch_taken, 1);

    dut->rs1_val = 0xFFFFFFFF; dut->rs2_val = 1; dut->eval(); tfp->dump(sim_time++);
    check("BGE: -1 >= 1 not taken", dut->branch_taken, 0);

    // BLTU unsigned (funct3=110)
    dut->funct3 = 0b110;
    dut->rs1_val = 1; dut->rs2_val = 0xFFFFFFFF; dut->eval(); tfp->dump(sim_time++);
    check("BLTU: 1 < 0xFFFFFFFF taken", dut->branch_taken, 1);

    dut->rs1_val = 0xFFFFFFFF; dut->rs2_val = 1; dut->eval(); tfp->dump(sim_time++);
    check("BLTU: 0xFFFFFFFF < 1 not taken", dut->branch_taken, 0);

    // BGEU unsigned (funct3=111)
    dut->funct3 = 0b111;
    dut->rs1_val = 0xFFFFFFFF; dut->rs2_val = 1; dut->eval(); tfp->dump(sim_time++);
    check("BGEU: 0xFFFFFFFF >= 1 taken", dut->branch_taken, 1);

    dut->rs1_val = 1; dut->rs2_val = 0xFFFFFFFF; dut->eval(); tfp->dump(sim_time++);
    check("BGEU: 1 >= 0xFFFFFFFF not taken", dut->branch_taken, 0);

    // is_branch=0 should suppress branch
    dut->is_branch = 0; dut->funct3 = 0b000;
    dut->rs1_val = 5; dut->rs2_val = 5; dut->eval(); tfp->dump(sim_time++);
    check("is_branch=0 suppresses taken", dut->branch_taken, 0);

    std::cout << "\nResults: " << passed << " passed, " << failed << " failed" << std::endl;
    tfp->close();
    delete dut;
    return failed > 0 ? 1 : 0;
}