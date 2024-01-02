#include <fork_snapshot/fork_snapshot.h>

volatile sig_atomic_t fork_flag = 0;
pid_t child_pid = -1;
uint64_t fork_cnt;

int store_snapshot(const char* filename);
void csr_prepare();

void handle_signal(int signum) {
    if (signum == SIGUSR1) {
        // kill child process
        fork_flag = 1; 
    }
    if (signum == SIGUSR2) {
        // save snapshot
        fork_flag = 2; 
    }
}

void init_fork(){
    // Register Process Interaction Signal
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    
    child_pid = fork();
    if (child_pid == -1) {
        perror("Cannot create child process");
    }
}

//Process Wait Wakeup Handling
void child_waitstore(){        
        // Check if it is a Child Process
        if (child_pid == 0) {
            while (!fork_flag) {
                sleep(1);
            }
            // save snapshot
            if(fork_flag ==2){
                printf("Child process pid:%d fork_flag:%d executes saving snapshot upon being awakened\n",getpid(),fork_flag);
                csr_prepare();
                int result = store_snapshot("snapshot.bin");

                if (result == -1) {
                    printf("Failed to complete snapshot\n");
                } else {
                    printf("Snapshot stored in snapshot.bin successfully.\n");
                }
            }
            exit(0);
        }
}

void fork_wakeup(int i){
        if(i == 1){
        kill(child_pid, SIGUSR1);
        }
        if(i == 2){
        kill(child_pid, SIGUSR2);
        }

        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            //printf(" Child pid:%d process exit,result:%d\n", child_pid,WEXITSTATUS(status));
        }
        
}
