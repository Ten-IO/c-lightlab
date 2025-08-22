#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
int main(){
	char cmd[MAX_LINE];
	while(1){
		printf(">> ");
		fgets(cmd, MAX_LINE, stdin);

		cmd[strcspn(cmd, "\n")]='\0';
		if (strcmp(cmd, "exit")==0)break;
		pid_t pid=fork();
		if(pid==0){
			char *args[]={cmd,NULL};
			execvp(args[0], args);
			printf("error: %s",*args);
			perror("pid failed execute");
			exit(1);
		} else if(pid>0) {
			wait(NULL);
		} else {
			perror("pid failed to fork");
			exit(1);
		}
	}
	return 0;
}
