#include "../header/client.h"
#include "../header/data.h"
#include "../header/routing.h"
#include <stdio.h>
#include "../header/pipe_controler.h"

#define BUFFER_SIZE 4096



int main() {

    Pipe* pipe1;
    Pipe* pipe2;

    create_pipe("pipe_1_right", "pipe_1_left");
    initialise_pipe(pipe1, "pipe_1_right", "pipe_1_left");
    create_pipe("pipe_2_right", "pipe_2_left");
    initialise_pipe(pipe1, "pipe_2_right", "pipe_2_left");

    ini_client();
    ini_routing();
    ini_data();
    interface_start();

    while(1) {
        while (1) {
            int choix = interface_choix();
            if (choix == 1) {
                break;
            }
            else if (choix == 0) {
                continue;
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
                int result0 = send_data_to_routing(answer.answer);
                if (result0 == 0) {
                    printf("Error while sending the request to the routing process\n");
                    break;
                }

                ask_for_file();



                break;
            }
        }
    }
}