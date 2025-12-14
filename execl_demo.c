#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) return 1;
    else if (pid == 0) {
        printf("\n[Child Process] Executing 'ls' command:\n");
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
    } else {
        wait(NULL);
        printf("\n[Parent Process] Executing 'date' command:\n");
        execl("/bin/date", "date", NULL);
        perror("execl failed");
    }
    return 0;
}
