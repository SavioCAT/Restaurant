#include <stdio.h>
#include <stdlib.h>
#include "../header/Pipe_cross.h"
#include "../header/Data.h"

int asking_for_data(char* name) {
    int pipe_Client_to_Routing = open_pipe("../File_pipe/pipe_Client_to_Routing"); //Opening the pipe
    int pipe_Routing_to_Client = open_pipe("../File_pipe/pipe_Routing_to_Client"); //Opening the pipe
    int pipe_Data_to_routing = open_pipe("../File_pipe/pipe_Data_to_Routing"); //Opening the pipe
    int pipe_Routing_to_Data = open_pipe("../File_pipe/pipe_Routing_to_Data"); //Opening the pipe

    //char* hearing_for_client = read_pipe(pipe_Client_to_Routing, buffer_hearing); //Reading the pipe

    int closing_the_pipe0 = close_pipe(pipe_Client_to_Routing); //Closing the pipe
    int closing_the_pipe1 = close_pipe(pipe_Routing_to_Client); //Closing the pipe
    int closing_the_pipe2 = close_pipe(pipe_Data_to_routing); //Closing the pipe
    int closing_the_pipe3 = close_pipe(pipe_Routing_to_Data); //Closing the pipe
    return 1;
}