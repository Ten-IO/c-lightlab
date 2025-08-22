/*
    [+] Process Identification and Grouping 
        • Write a C program to display: 
            o Process ID (PID) 
            o Parent Process ID (PPID) 
            o User ID (UID) 
            o Process Group ID (PGID) 
            o Display Session ID (SID) using getsid(0). 
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t pid = fork();
    if(pid == -1){
        perror("Fork error.");
        exit(1);
    }
    if(pid==0)
    printf("[+] Parent: %05d with ppid: %d and pid: %d\nuid: %d, gid: %d, pgid: %d, sid: %d\n", pid, getppid(), getpid(), getuid(), getgid(), __getpgid(0), getsid(0));
    else 
    printf("[-] Child : %d with ppid: %d and pid: %d\nuid: %d, gid: %d, pgid: %d, sid: %d\n", pid, getppid(), getpid(), getuid(), getgid(), getpgid(0), getsid(0));
    return 0;
}