#include "pipe_controler.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int create_pipe(char* name_1, char* name_2) {
    short pipe_1 = mkfifo(name_1, 0777);
    short pipe_2 = mkfifo(name_2, 0777);

    if (pipe_1 == 0 && pipe_2 == 0) {
        printf("Pipe created successfully");
        return 1;
    }
    else if (errno == EEXIST) {
        printf("Pipe already exist");
        return 1;
    }
    else {
        printf("Failed to create pipe");
        return -1;
    }
}

int initialise_pipe(Pipe* self, char* name_1, char* name_2) {
    if (self->id_in != -1 || self->id_out != -1) {
        printf("Pipe already open (or other problem)");
        return -2;
    }

    int open_in = open(name_1, O_RDWR);
    int open_out = open(name_1, O_RDWR);

    self->id_in = open_in;
    self->id_out = open_out;

    if (self->id_in > 0 || self->id_out > 0) {
        printf("Pipe successfully opened");
        return 1;
    }
    else {
        printf("Problem encountered while opening pipe");
        return -1;
    }
}

int write_pipe(Pipe* self, char* text) {
    if (self->id_out > 0) {
        char* buffer = (char*)malloc(BUFFER_SIZE); //Allocating memory for the buffer
        strcpy(buffer, text); //Copying the text to the buffer
        int writing = (int)write(self->id_out, buffer, BUFFER_SIZE);

        if (writing == -1) {
            printf("Error: Error while writing to the pipe: %d\n", self->id_out);
            return -1;
        }

        free(buffer);
        return 1;
    } else {
        printf("Can't write on the pipe");
        return -1;
    }
}

int read_pipe(Pipe* self, char* container) {
    if (self->id_in > 0) {
        int reading = (int)read(self->id_in, container, BUFFER_SIZE);

        if (reading == -1) {
            printf("Error: Error while reading from the pipe: %d\n", self->id_in);
            return -1;
        }

        return 1;
    }
    else {
        printf("Can't write on the pipe");
        return -1;
    }
}
