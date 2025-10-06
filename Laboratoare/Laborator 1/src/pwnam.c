#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {


    char *username = argv[1];
    struct passwd *pw = getpwnam(username);

    if(pw == NULL) {
        printf("User-ul '%s' nu exista.\n", username);
        return 1;
    }

    printf("User: %s\n", pw->pw_name);
    printf("Usern ID: %d\n", pw->pw_uid);
    printf("Group ID: %d\n", pw->pw_gid);
    printf("Home Directory: %s\n", pw->pw_dir);
    printf("Shell: %s\n", pw->pw_shell);

    return 0;

}
