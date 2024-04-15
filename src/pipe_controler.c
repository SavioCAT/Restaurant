#include "../header/pipe_controler.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define BUFFER_SIZE 4096

int is_pipe_empty(int pipe_id) {
    int count;
    ioctl(pipe_id, FIONREAD, &count);
    return count == 0;
}

int create_pipe(char* name_1, char* name_2) {
    short pipe_1 = mkfifo(name_1, 0777);
    short pipe_2 = mkfifo(name_2, 0777);

    if (pipe_1 == 0 && pipe_2 == 0) {
        printf("Pipe created successfully \n");
        return 1;
    }
    else if (errno == EEXIST) {
        printf("Pipe already exist \n");
        return 1;
    }
    else {
        printf("Failed to create pipe \n");
        return -1;
    }
}

int initialise_pipe(Pipe* self, char* name_1, char* name_2) {
    int open_in = open(name_1, O_RDWR);
    int open_out = open(name_2, O_RDWR);

    self->id_in = open_in;
    self->id_out = open_out;

    if (self->id_in > 0 || self->id_out > 0) {
        printf("Pipe successfully opened \n");
        return 1;
    }
    else {
        printf("Problem encountered while opening the pipe \n");
        return -1;
    }
}

int write_pipe(int self, char* text) {
    if (self > 0) {
        char* buffer = (char*)malloc(BUFFER_SIZE); //Allocating memory for the buffer
        strcpy(buffer, text); //Copying the text to the buffer
        int writing = (int)write(self, buffer, BUFFER_SIZE);

        if (writing == -1) {
            printf("Error: Error while writing to the pipe: %d\n", self);
            return -1;
        }

        free(buffer);
        return 1;
    } else {
        printf("Can't write on the pipe \n");
        return -1;
    }
}

int read_pipe(int self, char* container) {
    if (self > 0) {
        int reading = (int)read(self, container, BUFFER_SIZE);

        if (reading == -1) {
            //printf("Error: Error while reading from the pipe: %d\n", self); //DEBUG
            return -1;
        }

        return reading;
    }
    else {
        //printf("Can't read the pipe \n");
        return -1;
    }
}
