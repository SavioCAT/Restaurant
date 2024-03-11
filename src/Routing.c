#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/Pipe_cross.h"
#include "../header/Data.h"

char* buffer_hearing_what_client_asking;

char* asking_for_data_client() {
    int pipe_Client_to_Routing = open_pipe("../File_pipe/pipe_Client_to_Routing"); //Opening the pipe

    char* hearing_for_client = (char *)malloc(1024); //Allocating memory for the buffer who will read the file
    read_pipe(pipe_Client_to_Routing, hearing_for_client); //Reading the pipe
    strcpy(buffer_hearing_what_client_asking, hearing_for_client); //Reading the pipe

    int closing_the_pipe = close_pipe(pipe_Client_to_Routing); //Closing the pipe
    free(hearing_for_client);
    return ("Data received");
}

char* which_document_to_read(char* instruction) {
    asking_for_data_client();
    char* data = (char *)malloc(1024);
    strcpy(data, buffer_hearing_what_client_asking);
    char* name = (char *)malloc(64);

    switch(data) {
        case "Resto_1":
            strcpy(name, "../Data/Resto_1.txt");
            break;
        case "Resto_2":
            strcpy(name, "../Data/Resto_2.txt");
            break;
        case "Resto_3":
            strcpy(name, "../Data/Resto_3.txt");
            break;
        case "Resto_4":
            strcpy(name, "../Data/Resto_4.txt");
            break;
        case "Resto_5":
            strcpy(name, "../Data/Resto_5.txt");
            break;
        case "Resto_6":
            strcpy(name, "../Data/Resto_6.txt");
            break;
        case "Resto_7":
            strcpy(name, "../Data/Resto_7.txt");
            break;
        case "Resto_8":
            strcpy(name, "../Data/Resto_8.txt");
            break;
        case "Resto_9":
            strcpy(name, "../Data/Resto_9.txt");
            break;
        case "Resto_10":
            strcpy(name, "../Data/Resto_10.txt");
            break;
        default:
            strcpy(name, "../Data/Resto_1.txt");
            break;
    }

    free(data);
    free(name);
}

void distribute_data_to_client_pipe(char* name) {
    int pipe_Data_to_Routing = open_pipe("../File_pipe/pipe_Data_to_Routing"); //Opening the pipe to read the data from the file
    //read_txt_doc(); //Reading the file and writing the data to the pipe
}
