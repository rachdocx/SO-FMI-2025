#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    int fd = open("bin/myfifo", O_RDWR);
    if (fd < 0) {
        perror("open failed");
        exit(1);
    }

    pid_t pid = vfork();
    if (pid < 0) {
        perror("vfork failed");
        exit(1);
    }

    if (pid == 0) { 
        char c;
        read(fd, &c, 1); 
        printf("Child PID %d read: %c\n", getpid(), c);
        _exit(0);    
    } else {        
        write(fd, "a", 1); 
    }

    return 0;
}
