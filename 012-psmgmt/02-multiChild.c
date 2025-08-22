/*
	[+]  program that uses fork() to create three child processes. 
			• Parent prints all child PIDs and waits for all child process to finish. 
			• Each child should: 
				o Print its PID, PPID. 
				o Perform a unique task (e.g., sleep for 2, 4, and 6 seconds). 
				o Return exit status 0 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t child_pids[3];
	for (int i = 0; i < 3; i++)
	{
		pid_t pid = fork();

		if (pid < 0) {perror("Fork Failed"); exit(1);}
		else if (pid == 0)
		{
			printf("[+] Child %d (PID=%d) started\n", i + 1, getpid());
			sleep(i += 2);
			return 0;
		}
		else
			child_pids[i] = pid;
	}
	for (int i = 0; i < 3; i++)
	{
		waitpid(child_pids[i], NULL, 0);
		printf("[-] Parent: Child %d (PID=%d) terminated\n", i + 1, child_pids[i]);
	}
	printf("\n[-] Parent `(PID:%d) exiting\n", getpid());
	return 0;
}