/*
    [+] Create three children with different durations. 
            • Parent collects exit status using: 
                o wait() (basic) 
                o waitpid() (with PID-specific handling) 
            • Add logic to detect: 
                o Normal exit 
                o Signal termination 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pids[3];
    int durations[] = {2, 4, 6};
    for (int i = 0; i < 3; i++) 
        if ((pids[i] = fork()) == 0) {
            sleep(durations[i]);
            printf("Child %d done\n", getpid());
            exit(i); 
        }

    for (int i = 0; i < 3; i++) {
        int status;
        pid_t pid = waitpid(pids[i], &status, 0);
        if (WIFEXITED(status)) 
            printf("Child %d exited with code %d\n", pid, WEXITSTATUS(status));
         else if (WIFSIGNALED(status)) 
            printf("Child %d killed by signal %d\n", pid, WTERMSIG(status));
    }
    return 0;
}