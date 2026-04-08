#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Valu.h"
#include <iostream>

int passed = 0, failed = 0;
vluint64_t sim_time = 0;

void check(const char* test, uint32_t got, uint32_t expected) {
    if (got == expected) {
        std::cout << "  PASS: " << test << std::endl;
        passed++;
    } else {
        std::cout << " FAIL: " << test 
                  << " got=0x" << std::hex << got 
                  << " expected=0x" << expected << std::endl;
        failed++;
    }
}

int main() {
    Valu* dut = new Valu;
 
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    std::cout << "=== ALU Tests ===" << std::endl;

    // ADD
    dut->a = 10; dut->b = 5; dut->alu_op = 0x0;
    dut->eval(); tfp->dump(sim_time++);
    check("ADD 10+5=15", dut->result, 15);

    // SUB
    dut->a = 10; dut->b = 5; dut->alu_op = 0x1;
    dut->eval(); tfp->dump(sim_time++);
    check("SUB 10-5=5", dut->result, 5);

    // AND
    dut->a = 0xFF; dut->b = 0x0F; dut->alu_op = 0x2;
    dut->eval(); tfp->dump(sim_time++);
    check("AND 0xFF&0x0F=0x0F", dut->result, 0x0F);

    // OR
    dut->a = 0xF0; dut->b = 0x0F; dut->alu_op = 0x3;
    dut->eval(); tfp->dump(sim_time++);
    check("OR 0xF0|0x0F=0xFF", dut->result, 0xFF);

    // XOR
    dut->a = 0xFF; dut->b = 0xFF; dut->alu_op = 0x4;
    dut->eval(); tfp->dump(sim_time++);
    check("XOR 0xFF^0xFF=0", dut->result, 0);

    // SLL
    dut->a = 1; dut->b = 4; dut->alu_op = 0x5;
    dut->eval(); tfp->dump(sim_time++);
    check("SLL 1<<4=16", dut->result, 16);

    // SRL
    dut->a = 16; dut->b = 4; dut->alu_op = 0x6;
    dut->eval(); tfp->dump(sim_time++);
    check("SRL 16>>4=1", dut->result, 1);

    // SRA
    dut->a = 0xFFFFFFFF; dut->b = 4; dut->alu_op = 0x7;
    dut->eval(); tfp->dump(sim_time++);
    check("SRA -1>>4=0xFFFFFFFF", dut->result, 0xFFFFFFFF);

    // SLT
    dut->a = 0xFFFFFFFF; dut->b = 1; dut->alu_op = 0x8;
    dut->eval(); tfp->dump(sim_time++);
    check("SLT -1 < 1 = 1", dut->result, 1);

    // SLTU
    dut->a = 1; dut->b = 0xFFFFFFFF; dut->alu_op = 0x9;
    dut->eval(); tfp->dump(sim_time++);
    check("SLTU 1 < 0xFFFFFFFF = 1", dut->result, 1);

    // ZERO flag
    dut->a = 5; dut->b = 5; dut->alu_op = 0x1;
    dut->eval(); tfp->dump(sim_time++);
    check("ZERO flag: 5-5=0", dut->zero, 1);

    std::cout << "\nResults: " << passed << " passed, " << failed << " failed" << std::endl;

    tfp->close();
    delete dut;
    return failed > 0 ? 1 : 0;
}