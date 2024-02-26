#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int pipe0 = mkfifo(*Client_ServeurDeRoutage, 0777);
    int pipe1 = mkfifo(*ServeurDeRoutage_Client, 0777);

    return 0;
}