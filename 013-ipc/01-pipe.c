/*
    [+] Task: Create a program where a parent process sends a list of numbers to its child process. 
        The child calculates the sum and returns the result to the parent. 
        Steps: 
            1. Use pipe() to create two pipes: 
                o Pipe 1: Parent writes numbers, child reads. 
                o Pipe 2: Child writes sum, parent reads. 
            2. Parent sends integers (e.g., 5, 10, 15) via Pipe 1. 
            3. Child computes the sum and sends it back via Pipe 2. 
            4. Parent prints the result. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int pipe1[2], pipe2[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe err");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork err");
        exit(1);
    }
    if (pid == 0) {
        close(pipe1[1]);  
        close(pipe2[0]); 

        int nums[100], count = 0, val, sum = 0;  

        while (read(pipe1[0], &val, sizeof(int)) > 0) {
            nums[count++] = val;
        }

        for (int i = 0; i < count; i++) sum += nums[i];

        write(pipe2[1], &sum, sizeof(int));

        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        close(pipe1[0]);  
        close(pipe2[1]); 

        int numbers[] = {5, 10, 15}, result;

        for (int i = 0; i < 3; i++) 
            write(pipe1[1], &numbers[i], sizeof(int));
        close(pipe1[1]);  
        
        read(pipe2[0], &result, sizeof(int));
        printf("Sum received from child: %d\n", result);
        
        close(pipe2[0]);
        wait(NULL);
    }
    return 0;
}