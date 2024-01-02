#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h> 
#include <stdint.h>
#include  <time.h>

extern volatile sig_atomic_t fork_flag;
extern pid_t child_pid;
extern uint64_t fork_cnt;
extern struct lightqs_reg_ss spec_reg_ss;
void handle_signal(int signum);
void init_fork();
void child_waitstore();
void fork_wakeup(int i);
void isa_difftest_attach();
void csr_writeback();
void lightqs_take_reg_snapshot();
void lightqs_take_spec_reg_snapshot();
uint64_t lightqs_restore_reg_snapshot(uint64_t n);