//
// Created by user on 3/7/24.
//

#ifndef RESTAURANT_CLIENT_H
#define RESTAURANT_CLIENT_H

typedef struct {
    int code;
    char* answer;
} Answer;

Answer interface_menu();
void interface_start();
int interface_choix();
int ini_client();
int send_data_to_routing(char* request);

#endif //RESTAURANT_CLIENT_H
