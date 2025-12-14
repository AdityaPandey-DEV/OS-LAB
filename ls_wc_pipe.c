#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) return 1;
    pid_t pid = fork();
    if (pid < 0) return 1;
    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]); close(fd[1]);
        execlp("ls", "ls", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]); close(fd[1]);
        execlp("wc", "wc", NULL);
        perror("execlp failed");
        exit(1);
    }
    return 0;
}
