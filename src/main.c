#include "../header/client.h"
#include "../header/pipe.h"
#include "../header/data.h"
#include "../header/routing.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main() {
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