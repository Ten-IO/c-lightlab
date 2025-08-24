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
#include <time.h>
#define FIFO_PATH "weather_fifo"

int main() {
    mkfifo(FIFO_PATH, 0666);

    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    srand(time(NULL));
    while (1) {
        int temp = rand() % 30 + 15;
        write(fd, &temp, sizeof(int));
        printf("[Writer] Sent temperature: %d°C\n", temp);
        sleep(3);
    }
    close(fd);
    return 0;
}