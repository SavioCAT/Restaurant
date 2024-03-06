#include <stdio.h>
#include <stdlib.h>
#include "../header/Pipe_cross.h"

void interface_start() {
    printf("___________________________\n");
    printf("|     Project EL-3032     |\n");
    printf("|     Savio BOISSINOT     |\n");
    printf("|     Martin DEGUEURCE    |\n");
    printf("|_________________________|\n");
}

void interface() {
    interface_start();
    int choice;

    while(1) {
        printf("Welcome to the restaurant management system\n");
        printf("Please select an option:\n");
        printf("1. View the menu\n");
        printf("2. Close the application\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("You choose to look at the menus\n");
                break;
            case 2:
                printf("Goodbye !\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}