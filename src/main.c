#include <stdio.h>
#include "../header/Routing.h"
#include "../header/Pipe_cross.h"
#include "../header/Client.h"
#include "../header/Data.h"

#define BUFFER_SIZE 256

int main() {
    int pipe0 = open_pipe("../File_pipe/pipe_Data_to_Routing");
    read_txt_doc("../Data/Resto_1.txt");
    char buffer[BUFFER_SIZE];

    read_pipe(pipe0, buffer);
}