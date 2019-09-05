#ifndef __RISCV64_H__
#define __RISCV64_H__

#define ISA_QEMU_BIN "qemu-system-riscv64"
#define ISA_QEMU_ARGS 

#include "../../../../../../src/isa/riscv64/include/isa/diff-test.h"

union isa_gdb_regs {
  struct {
    uint64_t gpr[32];
    uint64_t pc;
  };
  struct {
    uint64_t array[77];
  };
};

#endif