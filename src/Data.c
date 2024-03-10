#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Pipe_cross.h"

int read_txt_doc(char* name) {
    int pipe_Data_to_routing = open_pipe("../File_pipe/pipe_Data_to_Routing"); //Opening the pipe
    FILE *f;
    printf("Opening the file: %s\n", name);
    f = fopen(name, "r"); //Opening the file in read mode

    char *buffer_read = (char *)malloc(sizeof(char) * 1024); //Allocating memory for the buffer who will read the file
    char *word = (char *)malloc(sizeof(char) * 64);

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }

    while (fscanf(f, "%s", word) != EOF) { //Reading the file and writing the data to the pipe
        strcat(buffer_read, word);
    }

    write_pipe("../File_pipe/pipe_Data_to_Routing", buffer_read);
    strcpy(buffer_read, ""); //Clearing the buffer

    fclose(f);
    int closing_the_pipe = close_pipe(pipe_Data_to_routing);
    free(buffer_read);
    free(word);
    return closing_the_pipe;
}

