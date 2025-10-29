#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Sunt copilul, PID = %d\n", getpid());
        _exit(0); 
    } else {
        printf("Sunt parintele, PID = %d, copilul are PID = %d\n", getpid(), pid);
        printf("Copilul va deveni zombie acum. Verifica cu 'ps'.\n");
        sleep(100); 
    }
    return 0;
}