#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "../header/pipe_controler.h"

#define BUFFER_SIZE 4096
#define STRING_SIZE 256

static Pipe local_server_pipe;
static int server_id;
static char file_address[64];
static int nb_max_client;
static int nb_server;
static char text[32];
static char request_restaurant[5];
static char request_menu[5];
static char request[STRING_SIZE];
static char buffer_read[BUFFER_SIZE];
static char word;

void ending_program(int signal) {
    if (signal == SIGINT) {
        printf("\nCTRL+C pressed, ending the process.\n");
        char old_name_right[64];
        char old_name_left[64];
        char new_name_right[64];
        char new_name_left[64];
        snprintf(old_name_right, sizeof(old_name_right), "used_pipe_server_right%d", server_id - 1);
        snprintf(old_name_left, sizeof(old_name_left), "used_pipe_server_left%d", server_id - 1);
        snprintf(new_name_right, sizeof(new_name_right), "pipe_server_right%d", server_id - 1);
        snprintf(new_name_left, sizeof(new_name_left), "pipe_server_left%d", server_id - 1);
        rename(old_name_right, new_name_right);
        rename(old_name_left, new_name_left);
        exit(0);
    }
}

void reset_value() {
    for (int i = 0; i < sizeof(text)/sizeof(char); i++) {
        text[i] = '\0';
    }
    for (int i = 0; i < sizeof(request_menu)/sizeof(char); i++) {
        request_menu[i] = '\0';
        request_restaurant[i] = '\0';
    }
    for (int i = 0; i < sizeof(request)/sizeof(char); i++) {
        request[i] = '\0';
        buffer_read[i] = '\0';
    }
    word = '\0';
}

int read_txt_doc() {
    reset_value();
    read_pipe(local_server_pipe.id_in, text);

    strncpy(request_restaurant, text + 5, 4);
    request_restaurant[4] = '\0';
    strncpy(request_menu, text + 10, 4);
    request_menu[4] = '\0';

    request[0] = '\0';
    strcat(request, file_address);
    strcat(request, "/");
    strcat(request, request_restaurant); strcat(request, "/");
    strcat(request, request_menu); strcat(request, ".txt"); //Creating the good path to the file who will be read

    FILE* f;
    f = fopen(request, "r"); //Opening the file in read mode

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", request);
        return 0;
    }

    while (fscanf(f, "%c", &word) != EOF) { //Reading the file and writing the data to the pipe
        strncat(buffer_read, &word, 1);
    }
    strcat(buffer_read, "\n");
    buffer_read[4095] = '\0';
    write_pipe(local_server_pipe.id_out, buffer_read); //Writing the data to the pipe

    fclose(f); //Closing the file
    return 1;
}

int main(int argc, char *argv[]) {
    signal(SIGINT, ending_program); // We're handling the case where the user press ctrl+c
    /**
     * Here we're verifying the number of arguments. I we've too much or not enought of arguments we're exiting the process.
     */
    if (argc > 3) {
        printf("Too much arguments\ntypo: ./main_server.out {id} {path}\n");
        exit(0);
    } else if (argc < 3) {
        printf("Not enought arguments\ntypo: ./main_server.out {id} {path}\n");
        exit(0);
    }
    printf("Press ctrl+c to kill the process\n");

    /**
     * This block is usefull to know the max of client and server.
     */
    FILE * file = fopen("value.txt", "r");
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

    server_id = atoi(argv[1]);
    snprintf(file_address, sizeof(file_address), "%s", argv[2]);

    char name_pipe_in[STRING_SIZE];
    char name_pipe_out[STRING_SIZE];
    snprintf(name_pipe_in, sizeof(name_pipe_in), "pipe_server_right%d",server_id - 1);
    snprintf(name_pipe_out, sizeof(name_pipe_out), "pipe_server_left%d",server_id - 1);

    int result = initialise_pipe(&local_server_pipe, name_pipe_in, name_pipe_out);
    if (result <= 0) {
        printf("Exiting the process.\n");
        exit(0);
    }

    char old_name_right[64];
    char old_name_left[64];
    char new_name_right[64];
    char new_name_left[64];
    snprintf(old_name_right, sizeof(old_name_right), "pipe_server_right%d", server_id-1);
    snprintf(old_name_left, sizeof(old_name_left), "pipe_server_left%d", server_id-1);
    snprintf(new_name_right, sizeof(new_name_right), "used_pipe_server_right%d", server_id-1);
    snprintf(new_name_left, sizeof(new_name_left), "used_pipe_server_left%d", server_id-1);
    rename(old_name_right, new_name_right);
    rename(old_name_left, new_name_left);

    while(1) {
        usleep(25000);
        if(is_pipe_empty(local_server_pipe.id_in) == 0) {
            printf("data received from routing.\n");
            read_txt_doc();
        }
    }
}