#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[], char *envp[]){
    int ok = chdir(argv[1]);
    if(ok ==-1){
        perror("eroare");
    }else{
        char temp[1024];
        if (getcwd(temp, sizeof(temp)) != NULL) {
            printf("directorul este: %s\n", temp);
        } else {
            perror("eroare");
        }
    }
    return 0;
}