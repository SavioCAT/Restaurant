#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int pipe0, pipe1;
char buffer_read[256];

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
    int writing = (int)write(write_pipe_acces, buffer, 1024);

    if (writing == -1) {
        printf("Error: Error while writing to the pipe: %s\n", NamePipe);
        return -1;
    }
    printf("Data written to the pipe: %s\n", buffer);
    return writing;
}

int read_pipe (int pipe_n, char *buffer) {
    int reading = (int)read(pipe_n, buffer, 1024);
    if (reading == -1) {
        printf("Error: Error while reading from the pipe: %d\n", pipe_n);
        return -1;
    }
    printf("Data read from the pipe: %s\n", buffer);
    return reading;
}

int initialise(int *pipe_n0, int *pipe_n1) {
    *pipe_n0 = open_pipe("../File_pipe/pipe_Client_to_Server");
    *pipe_n1 = open_pipe("../File_pipe/pipe_Server_to_Client");
    return 0;
}

int main(void) {
    initialise(&pipe0, &pipe1); //debugging
    write_pipe("../File_pipe/pipe_Server_to_Client", "Hello World !\n");
    read_pipe(pipe1, buffer_read);
    return 0;
}
