#include <stdio.h>
#include <stdlib.h>
#include "../header/Pipe_cross.h"

int read_txt_doc(char* name) {
    FILE *f;
    f = fopen(name, "r");

    if (f == NULL) {
        printf("Error: Error while opening the file: %s\n", name);
        return 0;
    }


}