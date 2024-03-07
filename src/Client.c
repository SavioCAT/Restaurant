#include <stdio.h>
#include <stdlib.h>
#include "../header/Pipe_cross.h"

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
    int choice;

    while(1) {
        printf("Which menu would you like to see ?\n");
        printf("1. The menu of the restaurant \"La brasserie\"\n");
        printf("2. Blablabla\n");
        printf("3. Blablabla\n");
        printf("4. Back\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou choose to look at the menu of the restaurant \"La brasserie\"\n");
                break;
            case 2:
                printf("Blablabla !\n");
                break;
            case 3:
                printf("Blablabla !\n");
                break;
            case 4:
                interface_choix();
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void ini_interface() {
    interface_start();
    interface_choix();
}

