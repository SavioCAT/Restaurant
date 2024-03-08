#include <stdio.h>
#include "../header/Routing.h"
#include "../header/Pipe_cross.h"
#include "../header/Client.h"

int main() {
    // initialise();
    // return 1;

    int pipe1 = open_pipe("../File_pipe/pipe_Client_to_Routing");
    int close1 = close_pipe(pipe1);
}