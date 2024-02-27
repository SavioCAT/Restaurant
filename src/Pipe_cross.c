#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int open_pipe (char* NamePipe) {
    int pipe = open(NamePipe, O_RDWR); //Opening the pipe in read and write
    printf("Pipe opened: %s \n", NamePipe);
    if (pipe == -1) {
        printf("Error: Error while opening the pipe: %s\n", NamePipe);
        return -1;
    }
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

int main(void) {
    int write = write_pipe("../File_pipe/pipe_Client_to_Server", "Hello, World!");

    return 0;
}
