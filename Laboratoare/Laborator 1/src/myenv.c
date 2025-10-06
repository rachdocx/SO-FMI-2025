#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[], char *envp[]){

    if(argc == 1){
        for(int i = 0; envp[i] != NULL; ++i)
            printf("%s\n", envp[i]);
    }

    if(argc == 2){
        int i;
        for(i = 0; envp[i] != NULL; ++i){

            char temp[1000], *p;
            strcpy(temp, envp[i]);
            p = strtok(temp, "=");

            if(strcmp(argv[1], p) == 0){
                p = strtok(NULL, "=");
                if(p)
                    printf("%s\n", p);
                break;
            }

        }
        if(envp[i] == NULL)
            printf("Variabila de mediu %s nu exista", argv[1]);
    }
    return 0;
}