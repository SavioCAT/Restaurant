#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];

    int pipe0 = mkfifo(*Client_ServeurDeRoutage, 0777);
    if (pipe0 != 0) {
        printf("Erreur lors de la création du pipe Client vers Serveur De Routage\n");
        return -1;
    }

    int pipe1 = mkfifo(*ServeurDeRoutage_Client, 0777);
    if (pipe1 != 0) {
        printf("Erreur lors de la création du pipe Serveur de Routage vers Client\n");
        return -1;
    }

    return 0;
}

int open_tube_client_to_server() {
    int pipe0 = open(*Client_ServeurDeRoutage, O_RDWR);
    if (pipe0 == -1) {
        printf("Erreur lors de l'ouverture du pipe Client vers Serveur De Routage\n");
        return -1;
    }
    return pipe0;
}

int open_tube_server_to_client() {
    int pipe1 = open(*ServeurDeRoutage_Client, O_RDWR);
    if (pipe1 == -1) {
        printf("Erreur lors de l'ouverture du pipe Serveur de Routage vers Client\n");
        return -1;
    }
    return pipe1;
}