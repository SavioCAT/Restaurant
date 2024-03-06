#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int pipe0, pipe1, pipe2, pipe3;
int *ppipe0 = &pipe0;
int *ppipe1 = &pipe1;
int *ppipe2 = &pipe2;
int *ppipe3 = &pipe3;
char buffer_read[1024];

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


int initialise() {
    *ppipe0 = open_pipe("../File_pipe/pipe_Client_to_Routing");
    *ppipe1 = open_pipe("../File_pipe/pipe_Routing_to_Client");
    *ppipe2 = open_pipe("../File_pipe/pipe_Routing_to_Data");
    *ppipe3 = open_pipe("../File_pipe/pipe_Data_to_Routing");
    return 0;
}
