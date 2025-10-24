#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[], char *envp[]){
    DIR *my_dir = opendir("bin/mydirector");
    struct dirent *content = readdir(my_dir);
    while((content = readdir(my_dir)) != NULL){
        printf("%s\n", content->d_name); 
    }
    closedir(my_dir);


    return 0;
}