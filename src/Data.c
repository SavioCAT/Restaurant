#include <stdio.h>
#include <stdlib.h>
#include "../header/Pipe_cross.h"

int read_txt_doc(char* name) {
    int pipe_Data_to_routing = open_pipe("../File_pipe/pipe_Data_to_Routing");
    FILE *f;
    f = fopen(name, "r");

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }

    fclose(f);
    int closing_the_pipe = close_pipe(pipe_Data_to_routing);
    return closing_the_pipe;
}