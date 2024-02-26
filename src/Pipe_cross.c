#include <stdio.h>
#include <fcntl.h>

int open_pipe (char* NamePipe) {
    int pipe = open(NamePipe, O_RDWR); //Opening the pipe in read and write
    if (pipe == -1) { //Check if the pipe has been opened, if not return -1 and display an error
        printf("Error while opening the pipe: %s\n", NamePipe);
        return -1;
    }
    printf("Pipe opened: %s\n", NamePipe);
    return pipe; //Send 0 if the pipe has been opened
}

int main(void) {
    int pipe_client_to_server = open_pipe("./File_pipe/pipe_Client_to_Server");
    int pipe_server_to_client = open_pipe("./File_pipe/pipe_Server_to_Client");

    return 0;
}