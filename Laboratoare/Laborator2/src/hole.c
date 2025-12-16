#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("fisier_cu_goluri", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    const char *text1 = "Hello";
    if (write(fd, text1, 5) != 5) {
        perror("write");
        exit(1);
    }

    if (lseek(fd, 100, SEEK_SET) < 0) {
        perror("lseek");
        exit(1);
    }

    const char *text2 = "World";
    if (write(fd, text2, 5) != 5) {
        perror("write");
        exit(1);
    }

    close(fd);
    return 0;
}
