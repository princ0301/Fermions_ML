#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vload_store_unit.h"
#include <iostream>

using namespace std;

int passed = 0, failed = 0;
vluint64_t sim_time = 0;

void check(const char* test, uint32_t got, uint32_t expected) {
    if (got == expected) {
        cout << "  PASS: " << test << endl;
        passed++;
    } else {
        cout << "  FAIL: " << test
            << " got=0x" << hex << got
            << " expected=0x" << expected << endl;
        failed++;
    }
}

int main() {
    Vload_store_unit* dut = new Vload_store_unit;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave_ls.vcd");

    std::cout << "=== Load/Store Unit Tests ===" << std::endl;
 
    dut->addr = 0x100; dut->wdata = 0x12345678;
    dut->funct3 = 0b010;  
    dut->mem_read = 0; dut->mem_write = 1;
    dut->eval(); tfp->dump(sim_time++);
    check("SW: mem_addr=0x100",    dut->mem_addr,  0x100);
    check("SW: byte_en=0xF",       dut->byte_en,   0xF);
    check("SW: wdata=0x12345678",  dut->mem_wdata, 0x12345678);
 
    dut->addr = 0x100; dut->wdata = 0xABCD;
    dut->funct3 = 0b001; 
    dut->mem_write = 1;
    dut->eval(); tfp->dump(sim_time++);
    check("SH: byte_en=0x3",       dut->byte_en,   0x3);
 
    dut->addr = 0x100; dut->wdata = 0xAB;
    dut->funct3 = 0b000; 
    dut->mem_write = 1;
    dut->eval(); tfp->dump(sim_time++);
    check("SB: byte_en=0x1",       dut->byte_en,   0x1);
 
    dut->addr = 0x100;
    dut->funct3 = 0b010; 
    dut->mem_read = 1; dut->mem_write = 0;
    dut->eval(); tfp->dump(sim_time++);
    check("LW: mem_addr=0x100",    dut->mem_addr,  0x100);
    check("LW: byte_en=0xF",       dut->byte_en,   0xF);
 
    dut->addr = 0x100;
    dut->funct3 = 0b000; 
    dut->mem_read = 1; dut->mem_write = 0;
    dut->eval(); tfp->dump(sim_time++);
    check("LB: mem_addr=0x100",    dut->mem_addr,  0x100);
    check("LB: byte_en=0x1",       dut->byte_en,   0x1);
 
    dut->addr = 0x100;
    dut->funct3 = 0b001; 
    dut->mem_read = 1;
    dut->eval(); tfp->dump(sim_time++);
    check("LH: byte_en=0x3",       dut->byte_en,   0x3);

    cout << "\nResults: " << passed << " passed, " << failed << " failed" << endl;
    tfp->close();
    delete dut;
    return failed > 0 ? 1 : 0;
}