#include <stdio.h>
#include <fcntl.h>

int open_tube_client_to_server() {
    char NomPipe0[] = "./File_pipe/pipe_Client_vers_Serveur"; //Adress to the pipe of communication between the client and the routing server
    int pipe0 = open(NomPipe0, O_RDWR); //Opening the pipe in read and write
    if (pipe0 == -1) { //Check if the pipe has been opened, if not return -1 and display an error
        printf("Error while opening the pipe Client to Server\n");
        return -1;
    }
    return pipe0; //Send 0 if the pipe has been opened
}

int open_tube_server_to_client() {
    char NomPipe1[] = "./File_pipe/pipe_Serveur_vers_Client"; //Adress to the pipe of communication between the routing server and the client
    int pipe1 = open(NomPipe1, O_RDWR); //Opening the pipe in read and write
    if (pipe1 == -1) { //Check if the pipe has been opened, if not return -1 and display an error
        printf("Error while opening the pipe Server to Client\n");
        return -1;
    }
    return pipe1; //Send 0 if the pipe has been opened
}

int main(void) {
    int pipe_client_to_server = open_tube_client_to_server();
    int pipe_server_to_client = open_tube_server_to_client();

    return 0;
}