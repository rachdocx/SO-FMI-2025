#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#define BUF_SIZE 8192
int main(int argc, char *argv[], char *envp[]){
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
        int flags = fcntl(fd_source, F_GETFL, 0);
        fcntl(fd_source, F_SETFL, flags | O_NONBLOCK);
    
    
        char buffer[BUF_SIZE];
        ssize_t bytes_read;

        while ((bytes_read = read(fd_source, buffer, BUF_SIZE)) > 0) {
            if (write(fd_dest, buffer, bytes_read) != bytes_read) {
                perror("Eroare la scrierea in fisier");
                close(fd_source);
                close(fd_dest);
                exit(1);
            }
        }

        if (bytes_read < 0) {
            perror("Eroare la citirea din fisier");
        }
}