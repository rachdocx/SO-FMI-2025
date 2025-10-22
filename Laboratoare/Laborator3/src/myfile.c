#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]){
    if (argc < 2){
        printf("Număr insuficient de argumente.\n");
        return 1;
    }
    for(int i = 0; i < argc; ++i){
        struct stat fisier;
        if(lstat(argv[i], &fisier) == -1){
            perror("Eroare la obținerea informațiilor despre fișier");
            continue;
        }
        printf("Informatie despre argumentul \n %d: \n %d: \n%d: \n%d: \n%d: \n%d: \n%d: \n%d: \n%d: \n", fisier.st_ino, fisier.st_size, fisier.st_mode, fisier.st_nlink, fisier.st_uid, fisier.st_gid, fisier.st_mtime, fisier.st_ctime);
    }
    return 0;
}