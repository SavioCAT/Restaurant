#include "../header/pipe_controler.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define STRING_SIZE 256


static Pipe pipe_client_0, pipe_client_1, pipe_client_2, pipe_client_3, pipe_client_4, pipe_client_5, pipe_client_6, pipe_client_7, pipe_client_8, pipe_client_9;
static Pipe pipe_server_0, pipe_server_1, pipe_server_2;


int main(int argc, char *argv[]) {
    char *container = malloc(sizeof(char) * 256);
    if (argc > 3) {
        printf("Too much args \n");
        exit(1);
    }
    else if (argc < 3) {
        printf("Not enought args \n");
        exit(1);
    }
    else if (atoi(argv[1]) > 5 || atoi(argv[1]) <= 0) {
        printf("Too much or not enought client, should be between 1 and 5 \n");
        exit(1);
    }
    else if (atoi(argv[2]) > 3 || atoi(argv[2]) <= 0) {
        printf("Too much or not enought server, should be between 1 and 3 \n");
        exit(1);
    }
    else {

        /**
         * This block is usefull to communicate the maximum of client and server in a text file reachable for every process.
         */
        FILE *file = fopen("value.txt", "w");
        if (file == NULL) {
            printf("Failed to open value.txt");
            exit(1);
        }
        fprintf(file, "%s\n", argv[1]); //maximum of client
        fprintf(file, "%s\n", argv[2]); //maximum of server
        fclose(file);

        /**
         * Here we're creating the pipe pour the communication between client-routing and routing-server
         */
        for (int i = 0; i < atoi(argv[1]); i++) {
            char name_pipe_client_right[STRING_SIZE];
            char name_pipe_client_left[STRING_SIZE];
            snprintf(name_pipe_client_right, sizeof(name_pipe_client_right), "pipe_client_right%d", i);
            snprintf(name_pipe_client_left, sizeof(name_pipe_client_left), "pipe_client_left%d", i);

            create_pipe(name_pipe_client_right, name_pipe_client_left);
        }
        for (int i = 0; i < atoi(argv[2]); i++) {
            char name_pipe_server_right[STRING_SIZE];
            char name_pipe_server_left[STRING_SIZE];
            snprintf(name_pipe_server_right, sizeof(name_pipe_server_right), "pipe_server_right%d", i);
            snprintf(name_pipe_server_left, sizeof(name_pipe_server_left), "pipe_server_left%d", i);

            create_pipe(name_pipe_server_right, name_pipe_server_left);
        }

        for (int i = 0; i < atoi(argv[1]); i++) {

        }
        for (int i = 0; i < atoi(argv[2]); i++) {
            char name_pipe_server_right[STRING_SIZE];
            char name_pipe_server_left[STRING_SIZE];
            snprintf(name_pipe_server_right, sizeof(name_pipe_server_right), "pipe_server_right%d", i);
            snprintf(name_pipe_server_left, sizeof(name_pipe_server_left), "pipe_server_left%d", i);

            create_pipe(name_pipe_server_right, name_pipe_server_left);
        }

        /**
         * hell block to initiliase all the pipe struct for the client.
         */
        if (atoi(argv[1]) == 1) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
        } else if (atoi(argv[1]) == 2) {
            initialise_pipe(&pipe_client_0, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_1, "pipe_client_right0", "pipe_client_left0");
        } else if (atoi(argv[1]) == 3) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
        } else if (atoi(argv[1]) == 4) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
        } else if (atoi(argv[1]) == 5) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
            initialise_pipe(&pipe_client_4, "pipe_client_right4", "pipe_client_left4");
        } else if (atoi(argv[1]) == 6) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
            initialise_pipe(&pipe_client_4, "pipe_client_right4", "pipe_client_left4");
            initialise_pipe(&pipe_client_5, "pipe_client_right5", "pipe_client_left5");
        } else if (atoi(argv[1]) == 7) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
            initialise_pipe(&pipe_client_4, "pipe_client_right4", "pipe_client_left4");
            initialise_pipe(&pipe_client_5, "pipe_client_right5", "pipe_client_left5");
            initialise_pipe(&pipe_client_6, "pipe_client_right6", "pipe_client_left6");
        } else if (atoi(argv[1]) == 8) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
            initialise_pipe(&pipe_client_4, "pipe_client_right4", "pipe_client_left4");
            initialise_pipe(&pipe_client_5, "pipe_client_right5", "pipe_client_left5");
            initialise_pipe(&pipe_client_6, "pipe_client_right6", "pipe_client_left6");
            initialise_pipe(&pipe_client_0, "pipe_client_right7", "pipe_client_left7");
        } else if (atoi(argv[1]) == 9) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
            initialise_pipe(&pipe_client_4, "pipe_client_right4", "pipe_client_left4");
            initialise_pipe(&pipe_client_5, "pipe_client_right5", "pipe_client_left5");
            initialise_pipe(&pipe_client_6, "pipe_client_right6", "pipe_client_left6");
            initialise_pipe(&pipe_client_7, "pipe_client_right7", "pipe_client_left7");
            initialise_pipe(&pipe_client_8, "pipe_client_right8", "pipe_client_left8");
        } else if (atoi(argv[1]) == 10) {
            initialise_pipe(&pipe_client_0, "pipe_client_right0", "pipe_client_left0");
            initialise_pipe(&pipe_client_1, "pipe_client_right1", "pipe_client_left1");
            initialise_pipe(&pipe_client_2, "pipe_client_right2", "pipe_client_left2");
            initialise_pipe(&pipe_client_3, "pipe_client_right3", "pipe_client_left3");
            initialise_pipe(&pipe_client_4, "pipe_client_right4", "pipe_client_left4");
            initialise_pipe(&pipe_client_5, "pipe_client_right5", "pipe_client_left5");
            initialise_pipe(&pipe_client_6, "pipe_client_right6", "pipe_client_left6");
            initialise_pipe(&pipe_client_7, "pipe_client_right7", "pipe_client_left7");
            initialise_pipe(&pipe_client_8, "pipe_client_right8", "pipe_client_left8");
            initialise_pipe(&pipe_client_9, "pipe_client_right9", "pipe_client_left9");
        }

        /**
         * Same but for the server.
         */
        if (atoi(argv[2]) == 1) {
            initialise_pipe(&pipe_server_0, "pipe_server_right0", "pipe_server_left0");
        } else if (atoi(argv[2]) == 2) {
            initialise_pipe(&pipe_server_0, "pipe_server_right1", "pipe_server_left1");
            initialise_pipe(&pipe_server_1, "pipe_server_right0", "pipe_server_left0");
        } else if (atoi(argv[2]) == 3) {
            initialise_pipe(&pipe_server_0, "pipe_server_right0", "pipe_server_left0");
            initialise_pipe(&pipe_server_1, "pipe_server_right1", "pipe_server_left1");
            initialise_pipe(&pipe_server_2, "pipe_server_right2", "pipe_server_left2");
        }
    }

    while(1) {
        if (atoi(argv[1]) == 1) {
            if (is_pipe_empty(pipe_client_0.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_0.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            }
        } else if (atoi(argv[1]) == 2) {
            if (is_pipe_empty(pipe_client_0.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_0.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_1.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_1.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            }
        } else if (atoi(argv[1]) == 3) {
            if (is_pipe_empty(pipe_client_0.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_0.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_1.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_1.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_2.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_2.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            }
        } else if (atoi(argv[1]) == 4) {
            if (is_pipe_empty(pipe_client_0.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_0.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_1.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_1.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_2.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_2.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_3.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_3.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_3.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_3.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_3.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            }
        } else if (atoi(argv[1]) == 5) {
            if (is_pipe_empty(pipe_client_0.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_0.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_0.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_1.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_1.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_1.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_2.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_2.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_2.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_3.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_3.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_3.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_3.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_3.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            } else if (is_pipe_empty(pipe_client_4.id_out) == 0) {
                char *container = malloc(sizeof(char) * 64);
                char address_server[4];
                int reading = read_pipe(pipe_client_4.id_out, container);
                if (reading <= 0) {
                    printf("Failed to read the pipe");
                    exit(1);
                }
                strncpy(address_server, container, 4);
                if (atoi(address_server) == 1 && atoi(argv[2]) >= 1) {
                    write_pipe(pipe_server_0.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_0.id_out, container_data);
                    write_pipe(pipe_client_4.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 2 && atoi(argv[2]) >= 2) {
                    write_pipe(pipe_server_1.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_1.id_out, container_data);
                    write_pipe(pipe_client_4.id_in, container_data);
                    free(container);
                    free(container_data);
                } else if (atoi(address_server) == 3 && atoi(argv[2]) >= 3) {
                    write_pipe(pipe_server_2.id_in, container);
                    char *container_data = malloc(sizeof(char) * BUFFER_SIZE);
                    read_pipe(pipe_server_2.id_out, container_data);
                    write_pipe(pipe_client_4.id_in, container_data);
                    free(container);
                    free(container_data);
                } else {
                    printf("Server unreachable !");
                }
            }
        }
    }
}