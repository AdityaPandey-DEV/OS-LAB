#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child Process (PID: %d) is running...\n", (int)getpid());
        sleep(2);
        printf("Child Process (PID: %d) has finished execution.\n", (int)getpid());
    } else {
        printf("Parent Process (PID: %d) is waiting for the child process to finish...\n", (int)getpid());
        pid_t a = wait(NULL);
        printf("Child process after wait returning process id %d\n", (int)a);
        printf("Parent Process (PID: %d) resumes after the child process has finished.\n", (int)getpid());
    }
    return 0;
}
