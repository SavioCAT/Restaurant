#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe_cross.h"
#include "../header/data.h"

char* find_request() {
    int pipe_0 = open_pipe("../file_pipe/pipe_client_to_routing");
    char* text = (char*) malloc(2056);
    read_pipe(pipe_0, text);
    close_pipe(pipe_0);
    return text;
}

/*
 * Return 1 if the request is valid, 0 if not
 */
int verify_request_shape(char* request) {
    if (strlen(request) == 14 && request[4] == '|' && request[9] == '|') {
        return 1;
    }
    else {
        return 0;
    }
}

void ask_for_file() {
    char* request_server = (char*) malloc(64);
    char* request_restaurant = (char*) malloc(64);
    char* request_menu  = (char*) malloc(64);
    char* request = (char*) malloc(512);

    char* file_name = (char*) malloc(64);
    int pipe_0 = open_pipe("../file_pipe/pipe_client_to_routing");
    read_pipe(pipe_0, file_name);
    close_pipe(pipe_0);

    for (int i = 0; i <= 3; i++) { //Extracting the data from the request
        request_server[i] = file_name[i];
        request_restaurant[i] = file_name[i+5];
        request_menu[i] = file_name[i+10];
    }

    strcpy(request, "../data/");
    strcat(request, request_server); strcat(request, "/");
    strcat(request, request_restaurant); strcat(request, "/");
    strcat(request, request_menu); strcat(request, ".txt"); //Creating the good path to the file who will be read
    write_pipe("../file_pipe/pipe_routing_to_data", request); //Sending the request to the pipe Routing to Data


    free(file_name);
    free(request_server);
    free(request_restaurant);
    free(request_menu);
    free(request);
}

void get_back_data_from_data() {
    int pipe_0 = open_pipe("../file_pipe/pipe_data_to_routing");
    char* text = (char*) malloc(4112);
    read_pipe(pipe_0, text);
    close_pipe(pipe_0);
    write_pipe("../file_pipe/pipe_routing_to_client", text);
}