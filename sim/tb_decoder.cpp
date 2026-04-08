#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vdecoder.h"
#include <iostream>

using namespace std;

int passed = 0, failed = 0;
vluint64_t sim_time = 0;

void check(const char* test, uint32_t got, uint32_t expected) {
    if (got == expected) {
        cout << "  PASS: " << test << endl;
        passed++;
    } else {
        cout << " FAIL: " << test
            << " got=0x" << hex << got
            << " expected=0x" << expected << endl;
        failed++;
    }
}

int main() {
    Vdecoder* dut = new Vdecoder;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave_decoder.vcd");

    cout << "=== Decoder Tests ===" << endl;

    // ADD x3, x1, x2 → R-type: funct7=0, rs2=2, rs1=1, funct3=0, rd=3, opcode=0110011
    // 0000000 00010 00001 000 00011 0110011
    dut->inst = 0x00208133; dut->eval(); tfp->dump(sim_time++);
    check("ADD: opcode=0110011", dut->opcode, 0b0110011);
    check("ADD: rs1=1",         dut->rs1,    1);
    check("ADD: rs2=2",         dut->rs2,    2);
    check("ADD: rd=3",          dut->rd,     3);
    check("ADD: funct3=0",      dut->funct3, 0);
    check("ADD: reg_write=1",   dut->reg_write, 1);
    check("ADD: mem_read=0",    dut->mem_read,  0);
    check("ADD: mem_write=0",   dut->mem_write, 0);
    check("ADD: branch=0",      dut->branch,    0);

    // ADDI x1, x0, 42 → I-type: imm=42, rs1=0, funct3=0, rd=1, opcode=0010011
    // 000000101010 00000 000 00001 0010011
    dut->inst = 0x02A00093; dut->eval(); tfp->dump(sim_time++);
    check("ADDI: opcode=0010011", dut->opcode, 0b0010011);
    check("ADDI: rs1=0",          dut->rs1,    0);
    check("ADDI: rd=1",           dut->rd,     1);
    check("ADDI: imm=42",         dut->imm,    42);
    check("ADDI: reg_write=1",    dut->reg_write, 1);
    check("ADDI: alu_src=1",      dut->alu_src,   1);

    // LW x2, 8(x1) → I-type load: imm=8, rs1=1, funct3=2, rd=2, opcode=0000011
    // 000000001000 00001 010 00010 0000011
    dut->inst = 0x00812103; dut->eval(); tfp->dump(sim_time++);
    check("LW: opcode=0000011",  dut->opcode,    0b0000011);
    check("LW: rs1=1",           dut->rs1,       1);
    check("LW: rd=2",            dut->rd,        2);
    check("LW: imm=8",           dut->imm,       8);
    check("LW: mem_read=1",      dut->mem_read,  1);
    check("LW: reg_write=1",     dut->reg_write, 1);

    // SW x2, 8(x1) → S-type: imm=8, rs2=2, rs1=1, funct3=2, opcode=0100011
    // 0000000 00010 00001 010 01000 0100011
    dut->inst = 0x00212423; dut->eval(); tfp->dump(sim_time++);
    check("SW: opcode=0100011",  dut->opcode,    0b0100011);
    check("SW: rs1=1",           dut->rs1,       1);
    check("SW: rs2=2",           dut->rs2,       2);
    check("SW: imm=8",           dut->imm,       8);
    check("SW: mem_write=1",     dut->mem_write, 1);
    check("SW: reg_write=0",     dut->reg_write, 0);

    // BEQ x1, x2, 8 → B-type: imm=8, rs1=1, rs2=2, funct3=0, opcode=1100011
    // imm[12|10:5]=0000000 rs2=00010 rs1=00001 funct3=000 imm[4:1|11]=01000 opcode=1100011
    dut->inst = 0x00208463; dut->eval(); tfp->dump(sim_time++);
    check("BEQ: opcode=1100011", dut->opcode, 0b1100011);
    check("BEQ: rs1=1",          dut->rs1,    1);
    check("BEQ: rs2=2",          dut->rs2,    2);
    check("BEQ: branch=1",       dut->branch, 1);
    check("BEQ: imm=8",          dut->imm,    8);

    cout << "\nResults: " << passed << " passed, " << failed << " failed" << endl;
    tfp->close();
    delete dut;
    return failed > 0 ? 1 : 0;
}