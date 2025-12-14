#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) return 1;
    else if (pid == 0) {
        printf("Child: PID = %d, parent PID = %d\n", (int)getpid(), (int)getppid());
        sleep(3);
        printf("Child after sleep: PID = %d, parent PID = %d\n", (int)getpid(), (int)getppid());
    } else {
        printf("Parent: PID = %d, exiting immediately\n", (int)getpid());
        exit(0);
    }
    return 0;
}
