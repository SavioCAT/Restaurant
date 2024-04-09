#include "../header/pipe_controler.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BUFFER_SIZE 4096
#define STRING_SIZE 256

static char container[STRING_SIZE];
static Pipe instruction_pipe;
static int open_pipe1;
static int open_pipe2;
static int nb_max_client;
static int nb_max_server;

//
//
//
// WIP
//
//
//

int main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("Too much args \0");
        exit(1);
    } else if (argc < 3) {
        printf("Not enought args \0");
        exit(1);
    }
    else {
        nb_max_client = atoi(argv[1]);
        nb_max_server = atoi(argv[2]);

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
        create_pipe("nb_max_client", "nb_max_server");
        open_pipe1 = open("nb_max_client", O_RDWR);
        open_pipe2 = open("nb_max_server", O_RDWR);
    }

    while(1) {
        while(1) {
            if (is_pipe_empty(open_pipe1) == 1) {
                char* text = malloc(sizeof(char) * 32);
                snprintf(text, sizeof(text), "%d", nb_max_client);
                write_pipe(open_pipe1, text);
                free(text);
            }
            if (is_pipe_empty(open_pipe2) == 1) {
                char* text = malloc(sizeof(char) * 32);
                snprintf(text, sizeof(text), "%d", nb_max_server);
                write_pipe(open_pipe2, text);
                free(text);
            }
            int result = -1;
            int i = 0;
            char pipe_name[STRING_SIZE];

            snprintf(pipe_name, sizeof(pipe_name), "pipe_client_right%d", i);
            if (i == nb_max_client) {
                i = 0;
            }
            i = i + 1;
            result = read_pipe(pipe_name, container);
            if (result == 1) {
                break;
            }
        }
        //write_pipe(, container);
    }
}