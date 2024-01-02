#include <cpu/cpu.h>
#include <cpu/exec.h>
#include <cpu/difftest.h>
#include <cpu/decode.h>
#include <memory/host-tlb.h>
#include <isa-all-instr.h>
#include <locale.h>
#include <setjmp.h>
#include <unistd.h>
#include <generated/autoconf.h>
#include <profiling/profiling_control.h>
#include <fork_snapshot/fork_snapshot.h>

extern CPU_state cpu;
extern uint64_t br_count;
extern uint64_t g_nr_guest_instr;

uint64_t stable_log_begin, spec_log_begin;
uint64_t br_count = 0;

extern int ifetch_mmu_state;
extern int data_mmu_state;
struct lightqs_reg_ss reg_ss, spec_reg_ss;
void csr_writeback();
void csr_prepare();

void lightqs_take_reg_snapshot() {
  csr_prepare();
  reg_ss.br_cnt = br_count;
  reg_ss.inst_cnt = g_nr_guest_instr;
#ifdef CONFIG_LIGHTQS_DEBUG
  printf("current g instr cnt = %lu\n", g_nr_guest_instr);
#endif // CONFIG_LIGHTQS_DEBUG
  reg_ss.pc = cpu.pc;
  reg_ss.mstatus = cpu.mstatus;
  reg_ss.mcause = cpu.mcause;
  reg_ss.mepc = cpu.mepc;
  reg_ss.sstatus = cpu.sstatus;
  reg_ss.scause = cpu.scause;
  reg_ss.sepc = cpu.sepc;
  reg_ss.satp = cpu.satp;
  reg_ss.mip = cpu.mip;
  reg_ss.mie = cpu.mie;
  reg_ss.mscratch = cpu.mscratch;
  reg_ss.sscratch = cpu.sscratch;
  reg_ss.medeleg = cpu.medeleg;
  reg_ss.mideleg = cpu.mideleg;
  reg_ss.mtval = cpu.mtval;
  reg_ss.stval = cpu.stval;
  reg_ss.mtvec = cpu.mtvec;
  reg_ss.stvec = cpu.stvec;
  reg_ss.mode = cpu.mode;
  reg_ss.lr_addr = cpu.lr_addr;
  reg_ss.lr_valid = cpu.lr_valid;
  reg_ss.ifetch_mmu_state = ifetch_mmu_state;
  reg_ss.data_mmu_state = data_mmu_state;
#ifdef CONFIG_RVV
  reg_ss.vtype = cpu.vtype;
  reg_ss.vstart = cpu.vstart;
  reg_ss.vxsat = cpu.vxsat;
  reg_ss.vxrm = cpu.vxrm;
  reg_ss.vl = cpu.vl;
#endif // CONFIG_RVV
  for (int i = 0; i < 32; i++) {
    reg_ss.gpr[i] = cpu.gpr[i]._64;
    reg_ss.fpr[i] = cpu.fpr[i]._64;
  }
}

void lightqs_take_spec_reg_snapshot() {
  csr_prepare();
  spec_reg_ss.br_cnt = br_count;
  spec_reg_ss.inst_cnt = g_nr_guest_instr;
  spec_reg_ss.pc = cpu.pc;
  spec_reg_ss.mstatus = cpu.mstatus;
  spec_reg_ss.mcause = cpu.mcause;
  spec_reg_ss.mepc = cpu.mepc;
  spec_reg_ss.sstatus = cpu.sstatus;
  spec_reg_ss.scause = cpu.scause;
  spec_reg_ss.sepc = cpu.sepc;
  spec_reg_ss.satp = cpu.satp;
  spec_reg_ss.mip = cpu.mip;
  spec_reg_ss.mie = cpu.mie;
  spec_reg_ss.mscratch = cpu.mscratch;
  spec_reg_ss.sscratch = cpu.sscratch;
  spec_reg_ss.medeleg = cpu.medeleg;
  spec_reg_ss.mideleg = cpu.mideleg;
  spec_reg_ss.mtval = cpu.mtval;
  spec_reg_ss.stval = cpu.stval;
  spec_reg_ss.mtvec = cpu.mtvec;
  spec_reg_ss.stvec = cpu.stvec;
  spec_reg_ss.mode = cpu.mode;
  spec_reg_ss.lr_addr = cpu.lr_addr;
  spec_reg_ss.lr_valid = cpu.lr_valid;
  spec_reg_ss.ifetch_mmu_state = ifetch_mmu_state;
  spec_reg_ss.data_mmu_state = data_mmu_state;
#ifdef CONFIG_RVV
  spec_reg_ss.vtype = cpu.vtype;
  spec_reg_ss.vstart = cpu.vstart;
  spec_reg_ss.vxsat = cpu.vxsat;
  spec_reg_ss.vxrm = cpu.vxrm;
  spec_reg_ss.vl = cpu.vl;
#endif // CONFIG_RVV
  for (int i = 0; i < 32; i++) {
    spec_reg_ss.gpr[i] = cpu.gpr[i]._64;
    spec_reg_ss.fpr[i] = cpu.fpr[i]._64;
  }
}

uint64_t lightqs_restore_reg_snapshot(uint64_t n) {
#ifdef CONFIG_LIGHTQS_DEBUG
  printf("lightqs restore reg n = %lu\n", n);
  printf("lightqs origin reg_ss inst cnt %lu\n", reg_ss.br_cnt);
#endif // CONFIG_LIGHTQS_DEBUG
  if (spec_log_begin <= n) {
#ifdef CONFIG_LIGHTQS_DEBUG
    printf("lightqs using spec snapshot\n");
#endif // CONFIG_LIGHTQS_DEBUG
    memcpy(&reg_ss, &spec_reg_ss, sizeof(reg_ss));
  }
  br_count = reg_ss.br_cnt;
  g_nr_guest_instr = reg_ss.inst_cnt;
  cpu.pc = reg_ss.pc;
  cpu.mstatus = reg_ss.mstatus;
  cpu.mcause = reg_ss.mcause;
  cpu.mepc = reg_ss.mepc;
  cpu.sstatus = reg_ss.sstatus;
  cpu.scause = reg_ss.scause;
  cpu.sepc = reg_ss.sepc;
  cpu.satp = reg_ss.satp;
  cpu.mip = reg_ss.mip;
  cpu.mie = reg_ss.mie;
  cpu.mscratch = reg_ss.mscratch;
  cpu.sscratch = reg_ss.sscratch;
  cpu.medeleg = reg_ss.medeleg;
  cpu.mideleg = reg_ss.mideleg;
  cpu.mtval = reg_ss.mtval;
  cpu.stval = reg_ss.stval;
  cpu.mode = reg_ss.mode;
  cpu.lr_addr = reg_ss.lr_addr;
  cpu.lr_valid = reg_ss.lr_valid;
  ifetch_mmu_state = reg_ss.ifetch_mmu_state;
  data_mmu_state = reg_ss.data_mmu_state;
#ifdef CONFIG_RVV
  cpu.vtype = reg_ss.vtype;
  cpu.vstart = reg_ss.vstart;
  cpu.vxsat = reg_ss.vxsat;
  cpu.vxrm = reg_ss.vxrm;
  cpu.vl = reg_ss.vl;
#endif // CONFIG_RVV
  for (int i = 0; i < 32; i++) {
    cpu.gpr[i]._64 = reg_ss.gpr[i];
    cpu.fpr[i]._64 = reg_ss.fpr[i];
  }
  csr_writeback();
#ifdef CONFIG_LIGHTQS_DEBUG
  printf("lightqs restore inst_cnt %lu\n", reg_ss.inst_cnt);
#endif // CONFIG_LIGHTQS_DEBUG
  return n - reg_ss.inst_cnt;
}

int store_snapshot(const char* filename) {
    FILE* fd = fopen(filename, "wb");
    if (fd == NULL) {
        printf("Can't open file: %s.\n", filename);
        return -1;
    }
    assert(fd != NULL);
    lightqs_take_spec_reg_snapshot();
    fwrite(&cpu, sizeof(cpu), 1, fd);
    fwrite(&spec_reg_ss, sizeof(spec_reg_ss), 1, fd);
    fwrite(guest_to_host(CONFIG_MBASE), MEMORY_SIZE, 1, fd);
    fclose(fd);
    return 0;
}