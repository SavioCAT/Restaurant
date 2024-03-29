#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/data.h"

#define BUFFER_SIZE 4096
Pipe* local_routing_pipe1;
Pipe* local_routing_pipe2;

char* find_request(Pipe pipe_1) {
    char* text = (char*) malloc(BUFFER_SIZE);
    read_txt_doc();
    return text;
}

/*
 * Return 1 if the request is valid, 0 if not
 * Verify if the request asked by the client is in the good shape.
 */
int verify_request_shape(char* request) {
    if (strlen(request) == 14 && request[4] == '|' && request[9] == '|') {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Recupere l'instruction dans le pipe client out et écris l'adresse voulu sous la bonne forme dans le pipe server in
 */
void ask_for_file() {
    char* request_server = (char*) malloc(5);
    char* request_restaurant = (char*) malloc(5);
    char* request_menu  = (char*) malloc(5);
    char* request = (char*) malloc(sizeof(char) * 24);

    char* file_name = (char*) malloc(BUFFER_SIZE);
    int retour = 0;
    do {
        retour = read_pipe(local_routing_pipe1->id_out, file_name); //Reading the request from the pipe (client to routing)
    } while (retour <= 0);

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
    write_pipe(local_routing_pipe2->id_in, request); //Sending the request to the data process


    free(file_name);
    free(request_server);
    free(request_restaurant);
    free(request_menu);
    free(request);
}

void get_back_data_from_data() {
    char* text = (char*) malloc(BUFFER_SIZE);
    read_pipe(local_routing_pipe2->id_out, text); //Reading the data from the data process
    write_pipe(local_routing_pipe1->id_in, text);
}

void ini_routing(Pipe* id_pipe1, Pipe* id_pipe2) {
    local_routing_pipe1 = id_pipe1;
    local_routing_pipe2 = id_pipe2;
}
