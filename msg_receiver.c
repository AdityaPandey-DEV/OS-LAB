#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512
#define QUEUE_KEY 1234

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_TEXT];
};

int main() {
    int msgid = msgget(QUEUE_KEY, IPC_CREAT | 0666);
    if (msgid == -1) return 1;
    struct msg_buffer message;
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) return 1;
    printf("Received message: %s\n", message.msg_text);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
