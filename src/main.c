#include <stdio.h>
#include <stdlib.h>
#include "../header/Routing.h"
#include "../header/Pipe_cross.h"
#include "../header/Client.h"
#include "../header/Data.h"

#define BUFFER_SIZE 256

int main() {
    write_pipe("../File_pipe/pipe_Client_to_Routing", "1");

    int pipe0 = open_pipe("../File_pipe/pipe_Client_to_Routing");
    char* text = (char*) malloc(32);
    read_pipe(pipe0, text);
    close_pipe(pipe0);
    printf("%s", text);
    free(text);
    exit(0);
}
