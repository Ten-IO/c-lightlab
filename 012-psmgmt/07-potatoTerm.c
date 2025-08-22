/*
	[+] Build a Mini Shell with Job Control
		• This shell reads user input, forks a process, and executes the command.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	char cmd[1024], *args[64];
	pid_t pid;
	int status;

	while (1)
	{
		printf("potato-shell> ");
		fflush(stdout);

		if (!fgets(cmd, sizeof(cmd), stdin))
			break;

		cmd[strcspn(cmd, "\n")] = 0;
		if (strcmp(cmd, "exit") == 0)
			break;
		if (strlen(cmd) == 0)
			continue;

		int i = 0;
		args[i] = strtok(cmd, " ");
		while (args[i] != NULL && i < 63)
		{
			i++;
			args[i] = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			continue;
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("cmd not found");
				exit(1);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
	printf("exiting shell\n");
	return 0;
}