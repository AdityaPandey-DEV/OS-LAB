#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char *messages[] = {"Message 1 from parent", "Message 2 from parent", "Message 3 from parent"};
    int num_messages = sizeof(messages) / sizeof(messages[0]);
    if (pipe(pipefd) == -1) return 1;
    pid = fork();
    if (pid < 0) return 1;
    if (pid > 0) {
        close(pipefd[0]);
        for (int i = 0; i < num_messages; i++) {
            write(pipefd[1], messages[i], strlen(messages[i]) + 1);
            sleep(1);
        }
        close(pipefd[1]);
        wait(NULL);
    } else {
        close(pipefd[1]);
        char buffer[256];
        while (read(pipefd[0], buffer, sizeof(buffer)) > 0) {
            printf("Child received: %s\n", buffer);
        }
        close(pipefd[0]);
    }
    return 0;
}
