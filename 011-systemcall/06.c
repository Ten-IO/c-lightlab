#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1
void print_line_number(int line) {
    char line_buf[32];
    snprintf(line_buf, sizeof(line_buf), "%d: ", line);
    write(STDOUT_FILENO, line_buf, strlen(line_buf));
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    char ch;
    int line = 1;
    print_line_number(line);

    while (read(fd, &ch, BUF_SIZE) > 0) {
        write(STDOUT_FILENO, &ch, 1);
        if (ch == '\n') {
            line++;
            print_line_number(line);
        }
    }
    close(fd);
    return 0;
}