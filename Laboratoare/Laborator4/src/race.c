#include <stdio.h>
#include <unistd.h>

void myprint(char *str) {
    char c;
    while ((c = *str++) != '\0') {
        write(1, &c, 1);
    }
}
int main(){
    pid_t pid = vfork();
    for(int i=0; i<20; i++){
            if(pid == 0){
        myprint("THIS IS THE CHILD PROCESS PRINTING\n");
        _exit(0);
    } else {
        myprint("This is the parent process printing\n");
    }
    myprint("\n");
    }   

    return 0;
}