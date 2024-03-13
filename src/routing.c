#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe_cross.h"
#include "../header/data.h"

char* find_request() {
    int pipe_0 = open_pipe("../file_pipe/pipe_Client_to_Routing");
    char* text = (char*) malloc(2056);
    read_pipe(pipe_0, text);
    close_pipe(pipe_0);
    return text;
}

/*
 * Return 1 if the request is valid, 0 if not
 */
int verify_request_shape(char* request) {
    if (strlen(request) == 14) {
        return 1;
    }
    else {
        return 0;
    }
}
