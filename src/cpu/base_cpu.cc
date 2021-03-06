#include "cpu/base_cpu.hh"

using namespace cpu;

BaseCPU::BaseCPU( unsigned gen_reg,
                  char* code,
                  unsigned entry_point,
                  interpreter::OpcodeManager& op_manager)
  : regs(gen_reg)
  , flags()
  , op_manager(op_manager)
  , bytecode_(code)
{
  regs.PC = entry_point;
  regs.SP = -1;
  regs.CSP = -1;
  regs.CP = -1;
}

BaseCPU::~BaseCPU()
{}
