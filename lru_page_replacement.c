#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) if (time[i] < min) { min = time[i]; pos = i; }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages;
    int frames[10], pages[30], time[10];
    int counter = 0, faults = 0;
    printf("Enter number of frames: "); if (scanf("%d", &no_of_frames) != 1) return 1;
    printf("Enter number of pages: "); if (scanf("%d", &no_of_pages) != 1) return 1;
    printf("Enter the page reference string:\n");
    for (int i = 0; i < no_of_pages; i++) scanf("%d", &pages[i]);
    for (int i = 0; i < no_of_frames; i++) frames[i] = -1;
    printf("\nStep\tRef\tFrames\n");
    for (int i = 0; i < no_of_pages; i++) {
        counter++;
        int page = pages[i], found = 0;
        for (int j = 0; j < no_of_frames; j++) if (frames[j] == page) { time[j] = counter; found = 1; break; }
        if (!found) {
            int placed = 0;
            for (int j = 0; j < no_of_frames; j++) if (frames[j] == -1) { frames[j] = page; time[j] = counter; faults++; placed = 1; break; }
            if (!placed) { int lru_index = findLRU(time, no_of_frames); frames[lru_index] = page; time[lru_index] = counter; faults++; }
        }
        printf("%d\t%d\t", i+1, page);
        for (int j = 0; j < no_of_frames; j++) if (frames[j] != -1) printf("%d ", frames[j]); else printf("- ");
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    printf("Page Fault Rate = %.2f%%\n", (float)faults / no_of_pages * 100);
    return 0;
}
