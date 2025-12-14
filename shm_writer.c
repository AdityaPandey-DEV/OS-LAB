#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

typedef struct { char data[100]; } shared_mem;

int main() {
    key_t key = ftok("/tmp", 65);
    int shmid = shmget(key, sizeof(shared_mem), 0666 | IPC_CREAT);
    shared_mem *shm_ptr = (shared_mem*) shmat(shmid, NULL, 0);
    for (int i = 1; i <= 200; i++) {
        sprintf(shm_ptr->data, "Message-%d", i);
        printf("[Writer] Wrote: %s\n", shm_ptr->data);
        usleep(100000);
    }
    shmdt(shm_ptr);
    return 0;
}
