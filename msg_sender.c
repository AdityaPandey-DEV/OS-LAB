#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512
#define QUEUE_KEY 1234

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_TEXT];
};

int main() {
    int msgid = msgget(QUEUE_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) return 1;
    struct msg_buffer message;
    message.msg_type = 1;
    if (fgets(message.msg_text, MAX_TEXT, stdin) == NULL) return 1;
    if (msgsnd(msgid, &message, strlen(message.msg_text) + 1, 0) == -1) return 1;
    return 0;
}
