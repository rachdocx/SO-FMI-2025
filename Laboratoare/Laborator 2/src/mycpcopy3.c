#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 8192
int main(int argc, char *argv[], char *envp[]){
    int n;
    if(argc != 3){
            printf("Nu ai introdus 2 argumente");
            exit(1);
        }

        int fd_source = open(argv[1], O_RDONLY);
        if(fd_source< 0){
            printf("Fisierul %s nu exista", argv[1]);
            exit(1);
        }

        int fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd_dest < 0){
            perror("Eroare la deschiderea fisierului destinatie");
            exit(1);    
        }

        //!!
    if (dup2(fd_source, 0) < 0) {
        perror("dup2 source -> stdin");
        exit(1);
    }

    if (dup2(fd_dest, 1) < 0) {
        perror("dup2 dest -> stdout");
        exit(1);
    }

    close(fd_source);
    close(fd_dest);

    char buf[BUFSIZE];
    while((n = read(0, buf, BUFSIZE)) > 0){
        if(write(1, buf, n) != n){
            perror("write");
            exit(1);
        }

    }
    if(n < 0){
        perror("read");
        exit(1);
    }
    exit(0);
}