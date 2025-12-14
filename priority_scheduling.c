#include <stdio.h>
#define MAX 50

int findHighestPriority(int n, int at[], int pr[], int rem_bt[], int completed[], int time) {
    int idx = -1, min_pr = 1e9;
    for (int i = 0; i < n; i++) if (at[i] <= time && completed[i] == 0 && rem_bt[i] > 0) {
        if (pr[i] < min_pr) { min_pr = pr[i]; idx = i; }
    }
    return idx;
}

void priorityPreemptive(int n, int at[], int bt[], int pr[]) {
    int ct[MAX], tat[MAX], wt[MAX], rem_bt[MAX], completed[MAX];
    for (int i = 0; i < n; i++) { rem_bt[i] = bt[i]; completed[i] = 0; }
    int completed_count = 0, time = 0;
    while (completed_count != n) {
        int idx = findHighestPriority(n, at, pr, rem_bt, completed, time);
        if (idx != -1) {
            rem_bt[idx]--; time++;
            if (rem_bt[idx] == 0) { completed[idx] = 1; completed_count++; ct[idx] = time; }
        } else time++;
    }
    int total_tat = 0, total_wt = 0;
    printf("\n--- Preemptive Priority Scheduling ---\n");
    printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) { tat[i] = ct[i] - at[i]; wt[i] = tat[i] - bt[i]; total_tat += tat[i]; total_wt += wt[i]; printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]); }
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
}

void priorityNonPreemptive() {
    int n; printf("Enter number of processes: "); if (scanf("%d", &n) != 1) return;
    int bt[n], at[n], priority[n], ct[n], tat[n], wt[n], pid[n], completed[n];
    for (int i = 0; i < n; i++) { pid[i] = i + 1; completed[i] = 0; printf("Enter Burst Time for P%d: ", pid[i]); scanf("%d", &bt[i]); printf("Enter Arrival Time for P%d: ", pid[i]); scanf("%d", &at[i]); printf("Enter Priority for P%d (Lower number = higher priority): ", pid[i]); scanf("%d", &priority[i]); }
    int total = 0, currentTime = 0, total_tat = 0, total_wt = 0;
    while (total < n) {
        int minPriority = 1e9, index = -1;
        for (int i = 0; i < n; i++) if (at[i] <= currentTime && completed[i] == 0) {
            if (priority[i] < minPriority) { minPriority = priority[i]; index = i; }
            else if (priority[i] == minPriority && at[i] < at[index]) index = i;
        }
        if (index == -1) { currentTime++; continue; }
        ct[index] = currentTime + bt[index]; tat[index] = ct[index] - at[index]; wt[index] = tat[index] - bt[index]; total_tat += tat[index]; total_wt += wt[index]; currentTime = ct[index]; completed[index] = 1; total++;
    }
    printf("\n--- Non-Preemptive Priority Scheduling ---\n");
    printf("PID\tBT\tAT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", pid[i], bt[i], at[i], priority[i], ct[i], tat[i], wt[i]);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
}

int main() {
    int choice; printf("Choose Scheduling Type:\n1. Preemptive Priority Scheduling\n2. Non-Preemptive Priority Scheduling\nEnter your choice: "); if (scanf("%d", &choice) != 1) return 1;
    if (choice == 1) {
        int n; printf("Enter number of processes: "); if (scanf("%d", &n) != 1) return 1;
        int at[MAX], bt[MAX], pr[MAX];
        for (int i = 0; i < n; i++) { printf("\nEnter Arrival Time, Burst Time, and Priority for Process %d (Lower number = higher priority): ", i+1); scanf("%d%d%d", &at[i], &bt[i], &pr[i]); }
        priorityPreemptive(n, at, bt, pr);
    } else if (choice == 2) priorityNonPreemptive(); else printf("Invalid choice!\n");
    return 0;
}
