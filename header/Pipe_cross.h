//
// Created by Savio BOISSINOT & Martin DEGUEURCE on 06/03/2024.
//

#ifndef RESTAURANT_PIPE_CROSS_H
#define RESTAURANT_PIPE_CROSS_H

int open_pipe (char* NamePipe);
int write_pipe (char* NamePipe, char* Text);
int read_pipe (int pipe_n, char *buffer);
int initialise();

#endif //RESTAURANT_PIPE_CROSS_H
