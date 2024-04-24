#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "../header/pipe_controler.h"
#include "../header/client.h"

#define BUFFER_SIZE 4096

static Pipe local_client_pipe;
static int nb_max_client;
static int nb_server;
static char name_pipe_right[64];
static char name_pipe_left[64];
static int result;
static int id_pipe;

void ending_process(int signal) {
    if (signal == SIGINT) {
        printf("\nCTRL+C pressed, ending the process.\n");
        char old_name_right[64];
        char old_name_left[64];
        char new_name_right[64];
        char new_name_left[64];
        snprintf(old_name_right, sizeof(old_name_right), "used_pipe_client_right%d", id_pipe);
        snprintf(old_name_left, sizeof(old_name_left), "used_pipe_client_left%d", id_pipe);
        snprintf(new_name_right, sizeof(new_name_right), "pipe_client_right%d", id_pipe);
        snprintf(new_name_left, sizeof(new_name_left), "pipe_client_left%d", id_pipe);
        rename(old_name_right, new_name_right);
        rename(old_name_left, new_name_left);
        exit(0);
    }
}

int verify_request_shape(char* request) {
    if (strlen(request) == 14 && request[4] == '|' && request[9] == '|') {
        return 1;
    }
    else {
        return 0;
    }
}

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
        printf("Press 1 to View the menu\n");
        printf("Press any other key to leave the application\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou choose to look at the menus\n");
                return 1;
            default:
                char old_name_right[64];
                char old_name_left[64];
                char new_name_right[64];
                char new_name_left[64];
                snprintf(old_name_right, sizeof(old_name_right), "used_pipe_client_right%d", id_pipe);
                snprintf(old_name_left, sizeof(old_name_left), "used_pipe_client_left%d", id_pipe);
                snprintf(new_name_right, sizeof(new_name_right), "pipe_client_right%d", id_pipe);
                snprintf(new_name_left, sizeof(new_name_left), "pipe_client_left%d", id_pipe);
                rename(old_name_right, new_name_right);
                rename(old_name_left, new_name_left);
                printf("Goodbye !\n");
                exit(0);
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

void show_answer_from_routing() {
    char* text = (char*) malloc(BUFFER_SIZE);
    read_pipe(local_client_pipe.id_in, text);
    printf("%s\n", text);
    free(text);
}

int send_data_to_routing(char* request, Pipe *pipe_pointer) {
    int result = write_pipe(local_client_pipe.id_out, request);
    if (result < 0) {
        exit(-1);
    }
    else {
        return 1;
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, ending_process); // We're handling the case where the client press ctrl+c.
    /**
     * This block is usefull to know the max of client and server.
     */
    FILE * file = fopen("value.txt", "r"); // Opening the file to know how many client is permitted and how many server is permitted.
    if (file == NULL) {
        printf("Failed to open value.txt\n");
        exit(1);
    }
    char line[BUFFER_SIZE];
    fgets(line, sizeof(line), file);
    nb_max_client = atoi(line);
    fgets(line, sizeof(line), file);
    nb_server = atoi(line);
    fclose(file);
    result = 0;

    /**
     * This block is usefull to search a free pipe to exchange instruction with routing process.
     */
    for (int i = 0; i < nb_max_client; i++) {
        snprintf(name_pipe_right, sizeof(name_pipe_right), "pipe_client_right%d", i);
        snprintf(name_pipe_left, sizeof(name_pipe_left), "pipe_client_left%d", i);

        result = initialise_pipe(&local_client_pipe, name_pipe_left, name_pipe_right);
        if (result > 0) {
            char old_name_right[64];
            char old_name_left[64];
            char new_name_right[64];
            char new_name_left[64];
            snprintf(old_name_right, sizeof(old_name_right), "pipe_client_right%d", i);
            snprintf(old_name_left, sizeof(old_name_left), "pipe_client_left%d", i);
            snprintf(new_name_right, sizeof(new_name_right), "used_pipe_client_right%d", i);
            snprintf(new_name_left, sizeof(new_name_left), "used_pipe_client_left%d", i);
            rename(old_name_right, new_name_right);
            rename(old_name_left, new_name_left);
            id_pipe = i;
            break;
        }
    }
    /**
     * If we find a free pipe we start to exchange data with routing. Else we're ending the program.
     */
    Answer ans;
    if (result > 0) {
        interface_start();
        while(1) {
            ans.code = -1;
            interface_choix();
            while (ans.code == -1) {
                ans = interface_menu();
            }
            if (ans.code == 0) {
                continue;
            }
            send_data_to_routing(ans.answer, &local_client_pipe);
            show_answer_from_routing();
        }
    } else {
        printf("No free pipe found, ending the program\n");
        exit(0);
    }
}
