#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int sumOfEven(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i += 2) sum += i;
    return sum;
}

int sumOfOdd(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i += 2) sum += i;
    return sum;
}

int main() {
    int n;
    if (printf("Enter the upper limit (n): ") < 0) return 1;
    if (scanf("%d", &n) != 1) return 1;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        int oddSum = sumOfOdd(n);
        printf("Child Process (PID: %d) - Sum of odd numbers: %d\n", (int)getpid(), oddSum);
    } else {
        wait(NULL);
        int evenSum = sumOfEven(n);
        printf("Parent Process (PID: %d) - Sum of even numbers: %d\n", (int)getpid(), evenSum);
    }
    return 0;
}
