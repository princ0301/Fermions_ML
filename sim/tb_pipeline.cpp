#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vriscv_pipeline.h"
#include <iostream>
#include <iomanip>

using namespace std;

vluint64_t sim_time = 0;

void tick(Vriscv_pipeline* dut, VerilatedVcdC* tfp) {
    dut->clk = 0; dut->eval(); 
    tfp->dump(sim_time++);
    dut->clk = 1; dut->eval(); 
    tfp->dump(sim_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vriscv_pipeline* dut = new Vriscv_pipeline;
    
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave_pipeline.vcd");

    uint32_t imem[16] = {
        0x00500093, // ADDI x1, x0, 5
        0x00000013, 0x00000013, 0x00000013,
        0x00A00113, // ADDI x2, x0, 10
        0x00000013, 0x00000013, 0x00000013,
        0x002081B3, // ADD x3, x1, x2 (15)
        0x00000013, 0x00000013, 0x00000013,
        0x00302023, // SW x3, 0(x0)
        0x00002203, // LW x4, 0(x0)
        0x00000013, 0x00000013
    };

    uint32_t dmem[256] = {0};

    dut->rst = 1;
    dut->instr_mem_data = 0x00000013;
    dut->data_mem_rdata = 0;
    tick(dut, tfp);
    tick(dut, tfp);
    dut->rst = 0;

    cout << "=== Pipeline Simulation ===" << std::endl;

    for (int i = 0; i < 40; i++) {
        uint32_t pc_idx = dut->instr_mem_addr >> 2;
        if (pc_idx < 16)
            dut->instr_mem_data = imem[pc_idx];
        else
            dut->instr_mem_data = 0x00000013;

        if (dut->data_mem_re) {
            uint32_t daddr = dut->data_mem_addr >> 2;
            if (daddr < 256)
                dut->data_mem_rdata = dmem[daddr];
        }

        if (dut->data_mem_we) {
            uint32_t daddr = dut->data_mem_addr >> 2;
            if (daddr < 256) {
                dmem[daddr] = dut->data_mem_wdata;
            }
        }

        cout << "Cycle " << std::dec << std::setw(2) << i 
            << " | PC=0x" << std::hex << std::setw(2) << dut->instr_mem_addr
            << " | Instr=0x" << std::setw(8) << std::setfill('0') << dut->instr_mem_data << std::setfill(' ');

        if (dut->data_mem_we) 
            cout << " [WRITE 0x" << dut->data_mem_addr << "=0x" << dut->data_mem_wdata << "]";
        if (dut->data_mem_re) 
            cout << " [READ 0x" << dut->data_mem_addr << "=0x" << dut->data_mem_rdata << "]";
        cout << endl;

        tick(dut, tfp);
    }

    cout << "Final dmem[0] = 0x" << hex << dmem[0] << " (Expected: 0xf)" << endl;

    tfp->close();
    delete dut;
    return 0;
}
