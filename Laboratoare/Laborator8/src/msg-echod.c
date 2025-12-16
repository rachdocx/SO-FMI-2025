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
int main(){
    int msgid;
    struct msg_buffer message;
    msgid = msgget(MSG_KEY,0666|IPC_CREAT);

    while(1){
        if(msgrcv(msgid, &message, sizeof(message.text), 1, 0) == -1){
            perror("er msgrcv");
            continue;
        }
        
        printf("primit: %s\n", message.text);

        message.msg_type = 2;

        if(msgsnd(msgid, &message, sizeof(message.text), 0) == -1){
            perror("er msgsnd");
        }
    }

    return 0;
}
