#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) return 1;
    if (pid == 0) {
        printf("Child: PID = %d\n", (int)getpid());
        exit(0);
    } else {
        printf("Parent: PID = %d, sleeping to keep zombie child...\n", (int)getpid());
        sleep(30);
        printf("Parent exiting.\n");
    }
    return 0;
}
