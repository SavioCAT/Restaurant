#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe.h"

#define BUFFER_SIZE 4096

Pipe pipe;

void startup_data(){
    pipe_init(&pipe, "../file_pipe/pipe_routing_to_data", "../file_pipe/pipe_data_to_routing");
}

char* reading_request_from_pipe() {
    char* text = (char*) malloc(BUFFER_SIZE); //Allocating memory for the text
    pipe_read(&pipe, text, BUFFER_SIZE); //Reading the request from the pipe
    return text;
}

int read_txt_doc() {
    char* name = reading_request_from_pipe(); //Reading the request from the pipe //DEBUG
    FILE* f;
    printf("%s\n", name); //DEBUG
    //printf("Opening the file: %s\n", name); //penser à décommenter pour debug
    f = fopen(name, "r"); //Opening the file in read mode

    char* buffer_read = (char *)malloc(BUFFER_SIZE); //Allocating memory for the buffer who will read the file
    char* word = (char *)malloc(BUFFER_SIZE);

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }

    while (fscanf(f, "%c", word) != EOF) { //Reading the file and writing the data to the pipe
        strcat(buffer_read, word);
    }
    strcat(buffer_read, "\n");
    pipe_write(&pipe, buffer_read); //Writing the data to the pipe

    //printf("%s", buffer_read); //debug
    strcpy(buffer_read, ""); //Clearing the buffer

    fclose(f); //Closing the file
    free(buffer_read);
    free(word);
    return 1;
}