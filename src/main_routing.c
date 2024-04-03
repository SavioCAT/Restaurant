#include "../header/client.h"
#include "../header/routing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define STRING_SIZE 256

int main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("Too much args \0");
        exit(1);
    } else if (argc < 3) {
        printf("Not enought args \0");
        exit(1);
    }
    else {
        int nb_max_client = atoi(argv[1]);
        int nb_max_server = atoi(argv[2]);

        for (int i = 0; i < nb_max_client; i++) {
            char name_pipe_client_right[STRING_SIZE];
            char name_pipe_client_left[STRING_SIZE];
            snprintf(name_pipe_client_right, sizeof(name_pipe_client_right), "pipe_client_right%d", i);
            snprintf(name_pipe_client_left, sizeof(name_pipe_client_left), "pipe_client_left%d", i);

            create_pipe(name_pipe_client_right, name_pipe_client_left);
        }
        for (int i = 0; i < nb_max_server; i++) {
            char name_pipe_server_right[STRING_SIZE];
            char name_pipe_server_left[STRING_SIZE];
            snprintf(name_pipe_server_right, sizeof(name_pipe_server_right), "pipe_server_right%d", i);
            snprintf(name_pipe_server_left, sizeof(name_pipe_server_left), "pipe_server_left%d", i);

            create_pipe(name_pipe_server_right, name_pipe_server_left);
        }
    }

    while(1) {
        while(1) {
            int result = -1;
            int i = 0;
            char container[STRING_SIZE];
            char pipe_name[STRING_SIZE];
            memset(chaine, 0, sizeof(chaine));

            snprintf(pipe_name, sizeof(pipe_name), "pipe_client_right%d", i);
            if (i == nb_max_client) {
                i = 0;
            }
            i = i + 1;
            result = read_pipe()
        }
    }
}