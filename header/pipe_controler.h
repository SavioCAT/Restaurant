#ifndef LIBRAIRIE_GESTION_PIPE_C_PIPE_CONTROLER_H
#define LIBRAIRIE_GESTION_PIPE_C_PIPE_CONTROLER_H

typedef struct {
    int id_in;
    int id_out;
}Pipe;

int create_pipe(char* name_1, char* name_2); // create an object pipe

int initialise_pipe(Pipe* self, char* name_1, char* name_2); // initialise the in and the out of the pipes

int write_pipe(int self, char* text); // write on the pipe out

int read_pipe(int self, char* container); // write the pipe in

int is_pipe_empty(int pipe_id); // return 1 if the pipe is empty, 0 if not.


#endif //LIBRAIRIE_GESTION_PIPE_C_PIPE_CONTROLER_H
