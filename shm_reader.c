#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

typedef struct { char data[100]; } shared_mem;

int main() {
    key_t key = ftok("/tmp", 65);
    int shmid = shmget(key, sizeof(shared_mem), 0666);
    shared_mem *shm_ptr = (shared_mem*) shmat(shmid, NULL, 0);
    for (int i = 1; i <= 200; i++) {
        printf("[Reader] Read : %s\n", shm_ptr->data);
        usleep(150000);
    }
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
