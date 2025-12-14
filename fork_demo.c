#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID = %d, Parent PID = %d\n", (int)getpid(), (int)getppid());
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n", (int)getpid(), (int)pid);
    }
    return 0;
}
