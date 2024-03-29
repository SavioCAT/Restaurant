#ifndef RESTAURANT_ROUTING_H
#define RESTAURANT_ROUTING_H
#include "pipe_controler.h"

int verify_request_shape(char* request);
void ask_for_file();
void get_back_data_from_data();
void startup_routing();
int ini_routing(Pipe* id_pipe1, Pipe* id_pipe2);

#endif //RESTAURANT_ROUTING_H
