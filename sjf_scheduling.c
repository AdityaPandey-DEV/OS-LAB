#include <stdio.h>
#define MAX 20

void sjfNonPreemptive() {
    int n; printf("Enter number of processes: "); if (scanf("%d", &n) != 1) return;
    int pid[MAX], at[MAX], bt[MAX], ct[MAX], tat[MAX], wt[MAX], completed[MAX];
    for (int i = 0; i < n; i++) { pid[i] = i + 1; printf("P%d Arrival Time: ", i+1); scanf("%d", &at[i]); printf("P%d Burst Time: ", i+1); scanf("%d", &bt[i]); completed[i] = 0; }
    int time = 0, count = 0;
    float avgTAT = 0, avgWT = 0;
    while (count < n) {
        int min_bt = 1e9, idx = -1;
        for (int i = 0; i < n; i++) if (at[i] <= time && completed[i] == 0) {
            if (bt[i] < min_bt) { min_bt = bt[i]; idx = i; }
        }
        if (idx != -1) {
            time += bt[idx]; ct[idx] = time; tat[idx] = ct[idx] - at[idx]; wt[idx] = tat[idx] - bt[idx]; avgTAT += tat[idx]; avgWT += wt[idx]; completed[idx] = 1; count++;
        } else time++;
    }
    printf("\n--- Non-Preemptive SJF (SJFNP) ---\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
    printf("Average Waiting Time = %.2f\n", avgWT / n);
}

void sjfPreemptive() {
    int n; printf("Enter number of processes: "); if (scanf("%d", &n) != 1) return;
    int at[MAX], bt[MAX], rt[MAX], ct[MAX], tat[MAX], wt[MAX], completed[MAX] = {0};
    for (int i = 0; i < n; i++) { printf("Enter Arrival time of P%d: ", i+1); scanf("%d", &at[i]); printf("Enter Burst time of P%d: ", i+1); scanf("%d", &bt[i]); rt[i] = bt[i]; }
    int time = 0, completed_count = 0;
    while (completed_count < n) {
        int min = 1e9, idx = -1;
        for (int i = 0; i < n; i++) if (at[i] <= time && completed[i] == 0) {
            if (rt[i] < min) { min = rt[i]; idx = i; }
        }
        if (idx != -1) {
            rt[idx]--; time++;
            if (rt[idx] == 0) { completed[idx] = 1; completed_count++; ct[idx] = time; tat[idx] = ct[idx] - at[idx]; wt[idx] = tat[idx] - bt[idx]; }
        } else time++;
    }
    float avg_tat = 0, avg_wt = 0;
    printf("\n--- Preemptive SJF (SRTF) ---\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) { printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]); avg_tat += tat[i]; avg_wt += wt[i]; }
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
    printf("Average Waiting Time = %.2f\n", avg_wt / n);
}

int main() {
    int choice; printf("Choose Scheduling Type:\n1. Non-Preemptive SJF (SJFNP)\n2. Preemptive SJF (SRTF)\nEnter your choice: ");
    if (scanf("%d", &choice) != 1) return 1;
    if (choice == 1) sjfNonPreemptive(); else if (choice == 2) sjfPreemptive(); else printf("Invalid choice!\n");
    return 0;
}
