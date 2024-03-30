#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe_controler.h"

#define BUFFER_SIZE 4096

static Pipe* local_server_pipe;

char* reading_request_from_pipe() {
    char* text = (char*) malloc(BUFFER_SIZE); //Allocating memory for the text
    read_pipe(local_server_pipe->id_in, text); //Reading the request from the pipe
    return text;
}

int read_txt_doc() {
    char* name = reading_request_from_pipe(); //Reading the request from the pipe //DEBUG
    FILE* f;
    //printf("%s\n", name); //DEBUG
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
    write_pipe(local_server_pipe->id_out, buffer_read); //Writing the data to the pipe

    //printf("%s", buffer_read); //debug
    strcpy(buffer_read, ""); //Clearing the buffer

    fclose(f); //Closing the file
    free(buffer_read);
    free(word);
    return 1;
}


void ini_data(Pipe* id_pipe) {
    local_server_pipe = id_pipe;
}
