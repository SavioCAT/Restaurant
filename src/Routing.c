#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Pipe_cross.h"
#include "../header/Data.h"

char* find_request() {
    int pipe_0 = open_pipe("../File_pipe/pipe_Client_to_Routing");
    char* text = (char*) malloc(2056);
    read_pipe(pipe_0, text);
    int closing = close_pipe(pipe_0);
    return text;
}

int verify_request_shape(char* request) {

}
