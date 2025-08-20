#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "[+] Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("[!] Error opening file");
        exit(1);
    }

    char buf[BUF_SIZE];
    int count = 0;
    int bytesRead;
    while ((bytesRead = read(fd, buf, BUF_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) 
            if (buf[i] == '\n') count++;
    }
    close(fd);
    printf("Total lines: %d\n", count);
    return 0;
}