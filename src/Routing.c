#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Pipe_cross.h"
#include "../header/Data.h"

char* buffer_hearing_what_client_asking;
char* name_of_the_file_client_asking;

char* asking_for_data_client() {
    int pipe_Client_to_Routing = open_pipe("../File_pipe/pipe_Client_to_Routing"); //Opening the pipe

    char* hearing_for_client = (char *)malloc(1024); //Allocating memory for the buffer who will read the file
    read_pipe(pipe_Client_to_Routing, hearing_for_client); //Reading the pipe
    strcpy(buffer_hearing_what_client_asking, hearing_for_client); //Reading the pipe

    int closing_the_pipe = close_pipe(pipe_Client_to_Routing); //Closing the pipe
    free(hearing_for_client);
    return ("Data received");
}

char* which_document_to_read() {
    asking_for_data_client();
    char* instruction = (char *)malloc(1024);
    strcpy(instruction, buffer_hearing_what_client_asking);



    free(instruction);
}

void distribute_data_to_client_pipe(char* name) {
    int pipe_Data_to_Routing = open_pipe("../File_pipe/pipe_Data_to_Routing"); //Opening the pipe to read the data from the file
    //read_txt_doc(); //Reading the file and writing the data to the pipe
}
