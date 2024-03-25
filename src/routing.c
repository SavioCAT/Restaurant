#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/data.h"
#include "../header/pipe.h"

#define BUFFER_SIZE 4096

Pipe pipe_routing_data;
Pipe pipe_client_routing;

void startup_routing(){
    pipe_init(&pipe_routing_data, "../file_pipe/pipe_data_to_routing", "../file_pipe/pipe_routing_to_data");
    pipe_init(&pipe_client_routing, "../file_pipe/pipe_client_to_routing", "../file_pipe/pipe_routing_to_client");
}

char* find_request() {
    char* text = (char*) malloc(BUFFER_SIZE);
    pipe_read(&pipe_client_routing, text, BUFFER_SIZE);
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
        retour = pipe_read(&pipe_client_routing, file_name, BUFFER_SIZE); //Reading the request from the pipe (client to routing)
    } while (retour == 0);

    printf("ce que récupère ask_for_file:%s\n", file_name);

    strncpy(request_server, file_name, 4);
    request_server[4] = '\0';
    strncpy(request_restaurant, file_name + 5, 4);
    request_restaurant[4] = '\0';
    strncpy(request_menu, file_name + 10, 4);
    request_menu[4] = '\0';

    printf("request avant traitement:%s\n", request);

    strcpy(request, "../data/");
    printf("request traitement1:%s\n", request);
    strcat(request, request_server); strcat(request, "/");
    printf("request traitement2:%s\n", request);
    strcat(request, request_restaurant); strcat(request, "/");
    printf("request traitement3:%s\n", request);
    strcat(request, request_menu); strcat(request, ".txt"); //Creating the good path to the file who will be read
    printf("request traitement4:%s\n", request);
    pipe_write(&pipe_routing_data, request); //Sending the request to the data process
    printf("flag what asking for ?: %s", request);


    free(file_name);
    free(request_server);
    free(request_restaurant);
    free(request_menu);
    free(request);
}

void get_back_data_from_data() {
    char* text = (char*) malloc(BUFFER_SIZE);
    pipe_read(&pipe_routing_data, text, BUFFER_SIZE); //Reading the data from the data process
    pipe_write(&pipe_client_routing, text);
}