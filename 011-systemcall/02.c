#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    int fd = open(argv[1], O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }
    const char *msg = argv[2];
    write(fd, msg, strlen(msg));
    close(fd);
    return 0;
}