/*
    [+] Task: Implement two separate programs (writer.c and reader.c) to simulate a weather station: 
        • Writer: Generates random temperatures (e.g., 20°C, 22°C) every 3 seconds and writes to 
            a FIFO. int temp = rand() % 30 + 15; // 15-45°C 
        • Reader: Reads from the FIFO and prints alerts for temperatures > 25°C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define FIFO_PATH "weather_fifo"

int main() {
    mkfifo(FIFO_PATH, 0666);

    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    int temp;
    while (read(fd, &temp, sizeof(int)) > 0) {
        printf("[Reader] Temp: %d°C\n", temp);
        if (temp > 25)
            printf("[!] Alert: High temperature!\n");
    }

    close(fd);
    return 0;
}