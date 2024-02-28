#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int pipe0, pipe1;

int open_pipe (char* NamePipe) {
    int pipe = open(NamePipe, O_RDWR); //Opening the pipe in read and write
    if (pipe == -1) {
        printf("Error: Error while opening the pipe: %s\n", NamePipe);
        return -1;
    }
    printf("Pipe opened: %s \n", NamePipe);
    return pipe;
}

int write_pipe (char* NamePipe, char* Text) {
    char* buffer = (char*)malloc(sizeof(Text) + 1); //Allocating memory for the buffer
    strcpy(buffer, Text); //Copying the text to the buffer
    int write_pipe_acces = open_pipe(NamePipe); //Opening the pipe
    int writing = (int)write(write_pipe_acces, buffer, sizeof(Text));

    if (writing == -1) {
        printf("Error: Error while writing to the pipe: %s\n", NamePipe);
        return -1;
    }
    printf("Data written to the pipe: %s\n", buffer);
    return writing;
}

int initialise(int *pipe_n0, int *pipe_n1) {
    *pipe_n0 = open_pipe("../File_pipe/pipe_Client_to_Server");
    *pipe_n1 = open_pipe("../File_pipe/pipe_Server_to_Client");
    return 0;
}

int main(void) {
    initialise(&pipe0, &pipe1); //debugging
    printf("Pipe 0: %d\n %p\n", pipe0, &pipe0); //debugging
    printf("Pipe 1: %d\n %p\n", pipe1, &pipe1); //debugging
    return 0;
}
