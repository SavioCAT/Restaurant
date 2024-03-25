#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/routing.h"
#include "../header/data.h"
#include "../header/pipe.h"
#define BUFFER_SIZE 4096

Pipe pipe1;

void interface_start();
void interface_choix();
void interface_menu();

void interface_start() {
    pipe_init(&pipe, "../file_pipe/pipe_routing_to_client", "../file_pipe/pipe_client_to_routing");
    startup_routing();
    startup_data();
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
    char* choice = (char*)malloc(BUFFER_SIZE);

    printf("Which menu would you like to see ?\n");
    printf("Type 0 to go back\n");
    printf("\nYour choice: ");
    scanf("%s", choice);
    pipe_write(&pipe1, choice);

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
        printf("flag demande: %s\n ", choice);

        int quantity = pipe_write(&pipe1, choice);
        if (quantity < 1) {
            printf("%d\n", quantity);
            exit(-1);
        }
        ask_for_file(); //Sending the request to the pipe Routing to Data
        int read = read_txt_doc();
        if (read == 0) {
            printf("Error: The file does not exist\n");
            free(choice);
            interface_menu();
        }
        get_back_data_from_data();

        char* answer = (char *) malloc(BUFFER_SIZE);
        pipe_read(&pipe1, answer, BUFFER_SIZE); //Reading the data from the pipe (data to routing

        printf("%s\n", answer);
        free(choice);
        interface_menu();
    }

    char* answer = (char *) malloc(BUFFER_SIZE);
    pipe_read(&pipe1, answer, BUFFER_SIZE); //Reading the data from the pipe (data to routing

    free(answer);
    free(choice);
}

void ini_interface() {
    interface_start();
    interface_choix();
}

