#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/pipe_cross.h"
#include "../header/routing.h"

void interface_start();
void interface_choix();
void interface_menu();


void interface_start() {
    printf("___________________________\n");
    printf("|     Project EL-3032     |\n");
    printf("|     Savio BOISSINOT     |\n");
    printf("|     Martin DEGUEURCE    |\n");
    printf("|_________________________|\n\n\n");
}

void interface_choix() {
    int choice;

    while(1) {
        printf("Welcome to the restaurant menu management application\n");
        printf("Please select an option:\n");
        printf("1. View the menu\n");
        printf("2. Close the application\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou choose to look at the menus\n");
                interface_menu();
            case 2:
                printf("Goodbye !\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void interface_menu() {
    char* choice = (char*)malloc(64);

    printf("Which menu would you like to see ?\n");
    printf("Type 0 to go back\n");
    printf("\nYour choice: ");
    scanf("%s", choice);
    write_pipe("../file_pipe/pipe_Client_to_Routing", choice);

    if (strcmp(choice, "0") == 0 && strlen(choice) == 1){
        free(choice);
        interface_choix();
        printf("\n");
    }
    else if (verify_request_shape(choice) == 0) {
        printf("Invalid choice\n\n");
        free(choice);
        interface_menu();
    }
    else {
        write_pipe("../file_pipe/pipe_Client_to_Routing", choice); //Sending the request to the pipe Client to Routing
        ask_for_file(); //Sending the request to the pipe Routing to Data
        free(choice);
        interface_menu();
    }


    int pipe0 = open_pipe("../file_pipe/pipe_Routing_to_Client");
    char* answer = (char *) malloc(2056);
    read_pipe(pipe0, answer);
    close_pipe(pipe0);

    free(answer);
    free(choice);
}

void ini_interface() {
    interface_start();
    interface_choix();
}

