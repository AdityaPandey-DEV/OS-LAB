#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1) return 1;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int tmp;
                tmp = at[i]; at[i] = at[j]; at[j] = tmp;
                tmp = bt[i]; bt[i] = bt[j]; bt[j] = tmp;
                tmp = pid[i]; pid[i] = pid[j]; pid[j] = tmp;
            }
        }
    }
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1]) ct[i] = at[i] + bt[i];
        else ct[i] = ct[i - 1] + bt[i];
    }
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTAT += tat[i]; avgWT += wt[i];
    }
    avgTAT /= n; avgWT /= n;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);
    printf("Average Waiting Time = %.2f\n", avgWT);
    return 0;
}
