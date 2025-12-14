#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages: ");
    if (scanf("%d", &n) != 1) return 1;
    int pages[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    if (scanf("%d", &f) != 1) return 1;
    int frames[f];
    for (int i = 0; i < f; i++) frames[i] = -1;
    int count = 0, index = 0;
    printf("\nPage Reference\tFrames\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) if (frames[j] == pages[i]) { found = 1; break; }
        if (!found) { frames[index] = pages[i]; index = (index + 1) % f; count++; }
        printf("%d\t\t", pages[i]);
        for (int j = 0; j < f; j++) { if (frames[j] != -1) printf("%d ", frames[j]); else printf("- "); }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", count);
    printf("Page Fault Rate = %.2f%%\n", (float)count / n * 100);
    return 0;
}
