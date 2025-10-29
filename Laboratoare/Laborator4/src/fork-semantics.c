#include <stdio.h>    
#include <unistd.h>   
#include <string.h>   
#include <sys/types.h> 
int global = 6;
char buf[1000] = "unbuffered write to stdout\n";
int main(){
    int local = 10;
    write(1, buf, strlen(buf));
    printf("inainte de fork\n");
    pid_t pid = fork();
    if(pid == 0){
        global++;
        local++;

    } else {
        sleep(2);
    }
        printf("pid = %d, global = %d, local = %d\n", getpid(), global, local);
}
