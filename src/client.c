#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/routing.h"
#include "../header/data.h"
#include "../header/client.h"
#include "../header/pipe_controler.h"
#define BUFFER_SIZE 4096

void interface_start();
int interface_choix();
Answer interface_menu();

Pipe *pointer_to_pipe_0;

//Graphic interface part
void interface_start() {
    printf("___________________________\n");
    printf("|     Project EL-3032     |\n");
    printf("|     Savio BOISSINOT     |\n");
    printf("|     Martin DEGUEURCE    |\n");
    printf("|_________________________|\n\n\n");
}

int interface_choix() {
    int choice;

        printf("Welcome to the restaurant menu management application\n");
        printf("Please select an option:\n");
        printf("1. View the menu\n");
        printf("2. Close the application\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou choose to look at the menus\n");
                return 1;
            case 2:
                printf("Goodbye !\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                return 0;
        }
}

Answer interface_menu() {
    char* choice = (char*)malloc(BUFFER_SIZE);
    Answer answer;

    printf("Which menu would you like to see ?\n");
    printf("Type 0 to go back\n");
    printf("\nYour choice: ");
    scanf("%s", choice);

    if (strcmp(choice, "0") == 0 && strlen(choice) == 1){
        free(choice);
        answer.code = 0;
        answer.answer = "\0";
        printf("\n");
        return answer;
    }
    else if (verify_request_shape(choice) == 0) {
        free(choice);
        answer.code = -1;
        answer.answer = "\0";
        printf("\n");
        return answer;
    }
    else {
        answer.code = 1;
        answer.answer = choice;
        return answer;
    }
}

//Logic part

/**
int ini_client() {
    Pipe pipe_0;
    create_pipe("pipe_client_in","pipe_client_out")
    pipe_init(&pipe_0, "pipe_Routing_to_Client", "pipe_Client_to_Routing");
    printf("in: %d\n", pipe_0.in);
    printf("out: %d\n", pipe_0.out);
    pointer_to_pipe_0 = &pipe_0;
    return 0;
}
**/

int send_data_to_routing(char* request, Pipe *pipe_pointer) {
    int result = write_pipe(pipe_pointer, request);
    if (result < 0) {
        exit(-1);
    }
    else {
        return 1;
    }
}