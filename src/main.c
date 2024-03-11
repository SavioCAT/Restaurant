#include <stdio.h>
#include <stdlib.h>
#include "../header/Routing.h"
#include "../header/Pipe_cross.h"
#include "../header/Client.h"
#include "../header/Data.h"

#define BUFFER_SIZE 256

int main() {

    char* text = (char *)malloc(2056);

    int test = open_pipe("../File_pipe/pipe_Data_to_Routing");
    read_txt_doc("../Data/Resto_1.txt");
    read_pipe(test, text);

    printf("%s", text);
    close_pipe(test);
    free(text);
}