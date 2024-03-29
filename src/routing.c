#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/data.h"
#include "../header/pipe.h"

#define BUFFER_SIZE 4096
Pipe *pointer_to_pipe_1;
Pipe *pointer_to_pipe_2;


char* find_request(Pipe pipe_1) {
    char* text = (char*) malloc(BUFFER_SIZE);
    pipe_read(&pipe_1, text, BUFFER_SIZE);
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
    char* request_server = (char*) malloc(5);
    char* request_restaurant = (char*) malloc(5);
    char* request_menu  = (char*) malloc(5);
    char* request = (char*) malloc(sizeof(char) * 24);

    char* file_name = (char*) malloc(BUFFER_SIZE);
    int retour = 0;
    do {
        retour = pipe_read(pointer_to_pipe_1, file_name, BUFFER_SIZE); //Reading the request from the pipe (client to routing)
    } while (retour == 0);

    printf("ce que récupère ask_for_file:%s\n", file_name);

    strncpy(request_server, file_name, 4);
    request_server[4] = '\0';
    strncpy(request_restaurant, file_name + 5, 4);
    request_restaurant[4] = '\0';
    strncpy(request_menu, file_name + 10, 4);
    request_menu[4] = '\0';

    strcpy(request, "../data/");
    strcat(request, request_server); strcat(request, "/");
    strcat(request, request_restaurant); strcat(request, "/");
    strcat(request, request_menu); strcat(request, ".txt"); //Creating the good path to the file who will be read
    pipe_write(pointer_to_pipe_2, request); //Sending the request to the data process


    free(file_name);
    free(request_server);
    free(request_restaurant);
    free(request_menu);
    free(request);
}

void get_back_data_from_data(Pipe pipe_1, Pipe pipe_2) {
    char* text = (char*) malloc(BUFFER_SIZE);
    pipe_read(pointer_to_pipe_2, text, BUFFER_SIZE); //Reading the data from the data process
    pipe_write(pointer_to_pipe_1, text);
}

int ini_routing() {
    Pipe pipe_1, pipe_2;
    pipe_init(&pipe_1, "pipe_Client_to_Routing", "pipe_Routing_to_Client");
    pipe_init(&pipe_2, "pipe_Routing_to_Data", "pipe_Data_to_Routing");
    printf("in: %d\n", pipe_1.in);
    printf("out: %d\n", pipe_1.out);
    printf("in: %d\n", pipe_2.in);
    printf("out: %d\n", pipe_2.out);
    pointer_to_pipe_1 = &pipe_1;
    pointer_to_pipe_2 = &pipe_2;
    return 0;
}