#include <stdlib.h> // exit
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h> // open
#include <string.h>

int main(int argc, char** argv){
	int f = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	
	if(f==-1){
		perror("Open");exit(1);
	}
	time_t now = time(NULL);
	char time_str[256];
	snprintf(time_str, sizeof(time_str),"%s\n", ctime(&now));
	write(f, time_str, strlen(time_str));
	close(f);
}