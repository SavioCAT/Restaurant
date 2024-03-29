#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H

#include "pipe_controler.h"

typedef struct {
    int code;
    char* answer;
} Answer;

Answer interface_menu();
void interface_start();
int interface_choix();
void ini_client(Pipe* id_pipe);
int send_data_to_routing(char* request, Pipe* pipe_pointer);
void show_answer_from_routing();

#endif //RESTAURANT_CLIENT_H
