#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Pipe_cross.h"
#include "../header/Data.h"

char* find_request() {
    int pipe0 = open_pipe("../File_pipe/pipe_Client_to_Routing");
    char *text = (char *) malloc(2056);
    read_pipe(pipe0, text);
    int closing = close_pipe(pipe0);

    return text;
}
