#ifndef BASE_CPU_HH
# define BASE_CPU_HH

# include <stack>

# include "cpu/registers.hh"
# include "cpu/flags.hh"

namespace cpu
{
  class BaseCPU
  {
    public:
      BaseCPU(unsigned gen_reg,
              unsigned char* code,
              unsigned entry_point);
      virtual ~BaseCPU();

      virtual void run() = 0;

      inline unsigned char fetch()
      {
        return bytecode_[regs.PC++];
      }

      Registers regs;
      Flags flags;
      std::stack<long long> stack;

    protected:
      unsigned char* bytecode_;
  };
}

#endif /* end of include guard: BASE_CPU_HH */