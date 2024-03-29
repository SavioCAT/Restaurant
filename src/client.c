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

Pipe* local_client_pipe;

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

void ini_client(Pipe* id_pipe) {
    local_client_pipe = id_pipe;
}


int send_data_to_routing(char* request, Pipe *pipe_pointer) {
    int result = write_pipe(local_client_pipe->id_out, request);
    if (result < 0) {
        exit(-1);
    }
    else {
        return 1;
    }
}