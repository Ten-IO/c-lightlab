/*
    [+] Build a basic chat system using two named pipes and threads. 
            Key Concepts: 
                • Multithreading with pthread_create. 
                • Synchronization (no shared memory, only FIFOs).
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define FIFO_SEND "fifoin"
#define FIFO_REC  "fifout"
#define BUFFER_SZ 256

void *receive_msg(void *arg){
        int fd = open(FIFO_REC, O_RDONLY);
        char buffer[BUFFER_SZ];
        while(true){
        int n = read(fd,buffer,BUFFER_SZ);
        if(n>0){
        buffer[n]='\0';
        printf("\nFriend: %s", buffer);
        fflush(stdout);
        }
        }
        close(fd);
        return NULL;
        }

        int main(){
        pthread_t rec_thread;
        pthread_create(&rec_thread, NULL, receive_msg, NULL);

        int fd  = open(FIFO_SEND, O_WRONLY);
        char buffer[BUFFER_SZ];

        printf("You can start chatting (type 'exit' to quit):\n");
        while(true){
            printf("You: ");
            fgets(buffer, BUFFER_SZ, stdin);
            write(fd, buffer, strlen(buffer));

            if(strncmp(buffer, "exit", 4)==0)
                break;
        }
        close(fd);
        pthread_cancel(rec_thread);
        return 0;
        }
