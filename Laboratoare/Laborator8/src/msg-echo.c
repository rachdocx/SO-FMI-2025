#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSG_KEY 1234
struct msg_buffer {
    long msg_type;
    char text[100];
};
int main(int argc, char *argv[]){
    int msgid;
    struct msg_buffer message;
    msgid = msgget(MSG_KEY, 0666);

    message.msg_type = 1;
    strncpy(message.text, argv[1], sizeof(message.text) - 1);
    message.text[sizeof(message.text) - 1] = '\0';    
    printf("mesaj: %s\n", message.text);
    
    return 0;
}
