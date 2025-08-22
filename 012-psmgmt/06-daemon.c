/*
    [+] Simple Daemon Process 
        • Fork and detach from terminal  
        • Logs the current time every 5 seconds into /tmp/daemon.log 
        • Run quietly in the background
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS); 

    setsid();  
    chdir("/"); 
    umask(0); 
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        FILE *fp = fopen("/tmp/daemon.log", "a+");
        if (fp) {
            time_t now = time(NULL);
            fprintf(fp, "Current time: %s", ctime(&now));
            fclose(fp);
        }
        sleep(5);
    }
    return 0;
}