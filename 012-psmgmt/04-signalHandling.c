/*
    [+] Fork a child that runs an infinite loop. 
        • Parent: 
            o Sends SIGTERM after 3 seconds. 
            o Sends SIGSTOP and SIGCONT to pause/resume the child. 
        • Child: 
            o Installs a handler for SIGTERM to print a message and exit cleanly.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handle_sigterm(int sig) {
    printf("Child received SIGTERM .. exiting cleanly\n");
    exit(0);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        signal(SIGTERM, handle_sigterm);
        while (1) {
            printf("Child running..\n");
            sleep(1);
        }
    } else {
        sleep(3);
        kill(pid, SIGSTOP); 
        sleep(2);
        kill(pid, SIGCONT); 
        sleep(2);
        kill(pid, SIGTERM); 
        wait(NULL);         
    }
    return 0;
}
