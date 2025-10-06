#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]){
    
    printf("UID: %d\n", getuid());
    printf("GID: %d\n", getgid());
    printf("PPID: %d\n", getpid());

    return 0;
}