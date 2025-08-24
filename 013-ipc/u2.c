/*
    [+] Build a basic chat system using two named pipes and threads. 
            Key Concepts: 
                • Multithreading with pthread_create. 
                • Synchronization (no shared memory, only FIFOs).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define FIFO_SEND "fifo1"
#define FIFO_RECV "fifo2"
#define BUFFER_SIZE 256

void* receive_message(void* arg) {
    int fd = open(FIFO_RECV, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open FIFO_RECV");
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int n = read(fd, buffer, BUFFER_SIZE - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("\nFriend: %s", buffer);
            fflush(stdout);
        }
    }

    close(fd);
    return NULL;
}

int main() {
    pthread_t recv_thread;
    pthread_create(&recv_thread, NULL, receive_message, NULL);

    int fd = open(FIFO_SEND, O_WRONLY);
    if (fd < 0) {
        perror("Failed to open FIFO_SEND");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    printf("You can start chatting (type 'exit' to quit):\n");

    while (1) {
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        write(fd, buffer, strlen(buffer));

        if (strncmp(buffer, "exit", 4) == 0)
            break;
    }

    close(fd);
    pthread_cancel(recv_thread);
    return 0;
}
