#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024
int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    char buf[BUF_SIZE];
    int bytesRead;
    while ((bytesRead = read(fd, buf, BUF_SIZE)) > 0) {
        write(STDOUT_FILENO, buf, bytesRead);
    }
    close(fd);
    return 0;
}
