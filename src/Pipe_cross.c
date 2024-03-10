#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int pipe0, pipe1, pipe2, pipe3;
int *ppipe0 = &pipe0;
int *ppipe1 = &pipe1;
int *ppipe2 = &pipe2;
int *ppipe3 = &pipe3;
char buffer_read[BUFFER_SIZE];

int open_pipe (char* NamePipe) {
    int pipe = open(NamePipe, O_RDWR); //Opening the pipe in read and write
    if (pipe == -1) {
        printf("Error: Error while opening the pipe: %s\n", NamePipe);
        return -1;
    }
    //printf("Pipe opened: %s \n", NamePipe); //penser à décommenter pour debug
    return pipe;
}

int close_pipe (int pipe_n) {
    int closing = close(pipe_n);
    if (closing == -1) {
        printf("Error: Error while closing the pipe: %d\n", pipe_n);
        return -1;
    }
    //printf("Pipe closed: %d \n", pipe_n); //penser à décommenter pour debug
    return closing;
}

int write_pipe (char* NamePipe, char* Text) {
    char* buffer = (char*)malloc(sizeof(Text)); //Allocating memory for the buffer
    strcpy(buffer, Text); //Copying the text to the buffer
    int write_pipe_acces = open_pipe(NamePipe); //Opening the pipe
    int writing = (int)write(write_pipe_acces, buffer, BUFFER_SIZE);

    if (writing == -1) {
        printf("Error: Error while writing to the pipe: %s\n", NamePipe);
        return -1;
    }
    //printf("Data written to the pipe: %s\n", buffer); //penser à décommenter pour debug
    return writing;
}

int read_pipe (int pipe_n, char *buffer) {
    int reading = (int)read(pipe_n, buffer, BUFFER_SIZE);
    if (reading == -1) {
        printf("Error: Error while reading from the pipe: %d\n", pipe_n);
        return -1;
    }
    printf("%s\n", buffer);
    return reading;
}
