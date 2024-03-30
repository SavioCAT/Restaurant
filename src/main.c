#include "../header/client.h"
#include "../header/data.h"
#include "../header/routing.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define STRING_SIZE 256
#define PID_SIZE 16

int main() {
    Pipe* client_pipe = malloc(sizeof(Pipe));
    Pipe* server_pipe = malloc(sizeof(Pipe));
    pid_t pid_process = getpid();
    char pid_string[PID_SIZE];
    snprintf(pid_string, sizeof(pid_string), "%d", pid_process);

    char name_pipe_client_right[STRING_SIZE];
    char name_pipe_client_left[STRING_SIZE];
    char name_pipe_server_right[STRING_SIZE];
    char name_pipe_server_left[STRING_SIZE];

    snprintf(name_pipe_client_right, sizeof(name_pipe_client_right), "pipe_client_right%s", pid_string);
    snprintf(name_pipe_client_left, sizeof(name_pipe_client_left), "pipe_client_left%s", pid_string);
    snprintf(name_pipe_server_right, sizeof(name_pipe_server_right), "pipe_server_right%s", pid_string);
    snprintf(name_pipe_server_left, sizeof(name_pipe_server_left), "pipe_server_left%s", pid_string);

    create_pipe(name_pipe_client_right, name_pipe_client_left);
    initialise_pipe(client_pipe, name_pipe_client_right, name_pipe_client_left);
    create_pipe(name_pipe_server_right, name_pipe_server_left);
    initialise_pipe(server_pipe, name_pipe_server_right, name_pipe_server_left);

    ini_client(client_pipe);
    ini_routing(client_pipe, server_pipe);
    ini_data(server_pipe);

    interface_start();

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
}