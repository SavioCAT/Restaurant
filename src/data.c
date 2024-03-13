#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe_cross.h"

int read_txt_doc(char* name) {
    int pipe_Data_to_routing = open_pipe("../file_pipe/pipe_Data_to_Routing"); //Opening the pipe
    FILE* f;
    //printf("Opening the file: %s\n", name); //penser à décommenter pour debug
    f = fopen(name, "r"); //Opening the file in read mode

    char* buffer_read = (char *)malloc(1024); //Allocating memory for the buffer who will read the file
    char* word = (char *)malloc(64);

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }

    while (fscanf(f, "%c", word) != EOF) { //Reading the file and writing the data to the pipe
        strcat(buffer_read, word);
    }
    strcat(buffer_read, "\n");
    write_pipe("../file_pipe/pipe_Data_to_Routing", buffer_read);

    //printf("%s", buffer_read); //debug
    strcpy(buffer_read, ""); //Clearing the buffer

    fclose(f);
    int closing_the_pipe = close_pipe(pipe_Data_to_routing);
    free(buffer_read);
    free(word);
    return closing_the_pipe;
}

