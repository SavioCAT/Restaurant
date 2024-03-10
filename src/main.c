#include <stdio.h>
#include "../header/Routing.h"
#include "../header/Pipe_cross.h"
#include "../header/Client.h"
#include "../header/Data.h"

int main() {
    int pipe0 = open_pipe("../File_pipe/pipe_Data_to_Routing");
    read_txt_doc("../Data/Resto_1.txt");


    char buffer[1024];

    read_pipe(pipe0, buffer);
    printf("Data read from the pipe: %s\n", buffer);
}