#ifndef LIBRAIRIE_GESTION_PIPE_C_PIPE_CONTROLER_H
#define LIBRAIRIE_GESTION_PIPE_C_PIPE_CONTROLER_H

typedef struct {
    int id_in;
    int id_out;
}Pipe;

int create_pipe(char* name_1, char* name_2); // create an object pipe

int initialise_pipe(Pipe* self, char* name_1, char* name_2); // initialise the in and the out of the pipes

int write_pipe(Pipe* self, char* text); // write on the pipe out

int read_pipe(Pipe* self, char* container); // write the pipe in


#endif //LIBRAIRIE_GESTION_PIPE_C_PIPE_CONTROLER_H
