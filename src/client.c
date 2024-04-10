#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../header/pipe_controler.h"
#include "../header/client.h"

#define BUFFER_SIZE 4096
#define STRING_SIZE 256
#define PID_SIZE 16

void interface_start();
int interface_choix();
Answer interface_menu();

static Pipe *local_client_pipe;
static Pipe pipe_client;
static int nb_max_client;
static int nb_server;

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
    read_pipe(local_client_pipe->id_in, text);
    printf("%s\n", text);
    free(text);
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

int main(int argc, char *argv[]) {

    int open_1 = open("./nb_max_client", O_RDWR);
    int open_2 = open("./nb_max_server", O_RDWR);
    char temp_nb_client[STRING_SIZE];
    char temp_nb_server[STRING_SIZE];
    read(open_1, temp_nb_client, 4);
    read(open_1, temp_nb_server, 4);
    nb_max_client = atoi(temp_nb_client);
    nb_server = atoi(temp_nb_server);


    printf("test %d %d",nb_max_client, nb_server);

    /**
    while(1) {
        while (1) {
            int choix = interface_choix();
            if (choix == 1) {
                break;
            }
        }

        while(1) {
            Answer answer = interface_menu();

            if (answer.code == 0) {
                break;
            }
            else if (answer.code == -1) {
                printf("Invalid choice\n");
                continue;
            }
            else {
                int result0 = send_data_to_routing(answer.answer, client_pipe);
                if (result0 == 0) {
                    printf("Error while sending the request to the routing process\n");
                    break;
                }

                ask_for_file();
                read_txt_doc();
                get_back_data_from_data();
                show_answer_from_routing();

                break;
            }
        }
    }
     **/
}