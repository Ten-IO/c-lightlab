#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid =fork();

	if(pid==0){
		char *args[]={"/bin/ls","-l",NULL};
		execvp(args[0], args);
	}else{
		wait(NULL);
		printf("child completed\n");
	}
	return 0;
}

