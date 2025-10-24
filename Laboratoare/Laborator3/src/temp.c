#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    fd = open("bin/tempfile", O_RDONLY);
    if(fd == -1){
        perror("Eroare la deschiderea fișierului");
    }
    if(unlink("bin/tempfile") == -1){
        perror("Eroare la ștergerea fișierului");
    }
    else{
        printf("Fișierul a fost șters cu succes.\n");
    }
    printf("Asteptati 15 secunde....\n");
    sleep(15);
    lseek(fd, 0, SEEK_SET);
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);  //functia read cu care citesti si returneaza nr de bytes cititi
    if (bytesRead == -1) {
        perror("Eroare la citirea fișierului");
    } else {
        buffer[bytesRead] = '\0';
        printf("Conținutul fișierului:\n%s\n", buffer);
    }
    close(fd);

    return 0;
}