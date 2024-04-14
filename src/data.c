#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../header/pipe_controler.h"

#define BUFFER_SIZE 4096
#define STRING_SIZE 256

static Pipe local_server_pipe;
static int server_id;
static char file_address[64];
static int nb_max_client;
static int nb_server;

char* reading_request_from_pipe() {

    char request[STRING_SIZE];
    strcat(request, file_address);

    char* text = (char*) malloc(BUFFER_SIZE); //Allocating memory for the text
    read_pipe(local_server_pipe.id_in, text); //Reading the request from the pipe
    return text;
}

int read_txt_doc() {
    char* name = reading_request_from_pipe(); //Reading the request from the pipe //DEBUG
    FILE* f;
    f = fopen(name, "r"); //Opening the file in read mode

    char* buffer_read = (char *)malloc(BUFFER_SIZE); //Allocating memory for the buffer who will read the file
    char* word = (char *)malloc(BUFFER_SIZE);

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }

    while (fscanf(f, "%c", word) != EOF) { //Reading the file and writing the data to the pipe
        strcat(buffer_read, word);
    }
    strcat(buffer_read, "\n");
    write_pipe(local_server_pipe.id_out, buffer_read); //Writing the data to the pipe

    //printf("%s", buffer_read); //debug
    strcpy(buffer_read, ""); //Clearing the buffer

    fclose(f); //Closing the file
    free(buffer_read);
    free(word);
    return 1;
}

int main(int argc, char *argv[]) {
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
    snprintf(name_pipe_out, sizeof(name_pipe_in), "pipe_server_left%d",server_id - 1);

    initialise_pipe(&local_server_pipe, name_pipe_in, name_pipe_out);

    while(1) {
        usleep(50000);

        if(is_pipe_empty(local_server_pipe.id_in) == 0) {

        }
    }
}