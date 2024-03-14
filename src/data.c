#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe_cross.h"

#define BUFFER_SIZE 4096

char* reading_request_from_pipe() {
    int pipe_0 = open_pipe("../file_pipe/pipe_routing_to_data"); //Opening the pipe
    char* text = (char*) malloc(BUFFER_SIZE); //Allocating memory for the text
    read_pipe(pipe_0, text); //Reading the pipe
    close_pipe(pipe_0); //Closing the pipe
    return text;
}

int read_txt_doc() {
    int pipe_Data_to_routing = open_pipe("../file_pipe/pipe_data_to_routing"); //Opening the pipe
    char* name = reading_request_from_pipe(); //Reading the request from the pipe //DEBUG
    printf("Flag0\n");
    FILE* f;
    printf("Flag0.5\n");
    printf("%s\n", name); //DEBUG
    //printf("Opening the file: %s\n", name); //penser à décommenter pour debug
    f = fopen(name, "r"); //Opening the file in read mode

    printf("Flag1\n");
    char* buffer_read = (char *)malloc(BUFFER_SIZE); //Allocating memory for the buffer who will read the file
    printf("Flag2\n");
    char* word = (char *)malloc(BUFFER_SIZE);

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }

    while (fscanf(f, "%c", word) != EOF) { //Reading the file and writing the data to the pipe
        strcat(buffer_read, word);
    }
    strcat(buffer_read, "\n");
    write_pipe("../file_pipe/pipe_data_to_routing", buffer_read);

    //printf("%s", buffer_read); //debug
    strcpy(buffer_read, ""); //Clearing the buffer

    fclose(f);
    int closing_the_pipe = close_pipe(pipe_Data_to_routing);
    free(buffer_read);
    free(word);
    return closing_the_pipe;
}

