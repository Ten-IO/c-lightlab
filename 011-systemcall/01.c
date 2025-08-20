#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int src = open(argv[1],O_RDONLY);
	int des = open(argv[2],O_WRONLY|O_CREAT,0644);

	if(src==-1||des==-1){
		perror("open"); exit(1);
	}
	char buf[1024];
	ssize_t r = read(src,buf,sizeof(buf));
	write(des,buf,r);
	close(src);
	close(des);
}
