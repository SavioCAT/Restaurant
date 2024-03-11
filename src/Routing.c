#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Pipe_cross.h"
#include "../header/Data.h"

char* buffer_hearing;

/**
 *  read the data from the pipe to know what the client want.
 */
char* asking_for_data_client() {
    int pipe_Client_to_Routing = open_pipe("../File_pipe/pipe_Client_to_Routing"); //Opening the pipe

    char* hearing_for_client = (char *)malloc(1024); //Allocating memory for the buffer who will read the file
    strcpy(hearing_for_client, read_pipe(pipe_Client_to_Routing, buffer_hearing)); //Reading the pipe

    int closing_the_pipe0 = close_pipe(pipe_Client_to_Routing); //Closing the pipe
    free(buffer_hearing);
    return ("Inside the Routing: The client want: %s", hearing_for_client);
}

char* which_document_to_read(char* instruction) {
    char* data = asking_for_data_client();
    char* name = (char *)malloc(1024);
}

void distribute_data_to_client_pipe(char* name) {
    int pipe_Data_to_Routing = open_pipe("../File_pipe/pipe_Data_to_Routing"); //Opening the pipe to read the data from the file
    //read_txt_doc(); //Reading the file and writing the data to the pipe
}