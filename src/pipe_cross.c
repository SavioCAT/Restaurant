#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

char buffer_read[BUFFER_SIZE];

int open_pipe (char* name_pipe) {
    int pipe = open(name_pipe, O_RDWR, O_NONBLOCK); //Opening the pipe in read and write
    if (pipe == -1) {
        printf("Error: Error while opening the pipe: %s\n", name_pipe);
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

int write_pipe (char* name_pipe, char* text) {
    char* buffer = (char*)malloc(256); //Allocating memory for the buffer
    strcpy(buffer, text); //Copying the text to the buffer
    int write_pipe_acces = open_pipe(name_pipe); //Opening the pipe
    int writing = (int)write(write_pipe_acces, buffer, BUFFER_SIZE);

    if (writing == -1) {
        printf("Error: Error while writing to the pipe: %s\n", name_pipe);
        return -1;
    }
    //printf("data written to the pipe: %s\n", buffer); //penser à décommenter pour debug
    free(buffer);
    return writing;
}

char* read_pipe (int pipe_n, char* buffer) {
    int reading = (int)read(pipe_n, buffer, BUFFER_SIZE);
    if (reading == -1) {
        printf("Error: Error while reading from the pipe: %d\n", pipe_n);
        return "Error";
    }
    //printf("%s\n", buffer); //Debug
    return buffer;
}