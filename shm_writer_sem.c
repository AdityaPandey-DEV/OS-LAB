#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_KEY 0x1234
#define SEM_KEY 0x5678

typedef struct { int number; } shared_mem;

void sem_wait(int semid, int sem_num) { struct sembuf sb = {sem_num, -1, 0}; semop(semid, &sb, 1); }
void sem_signal(int semid, int sem_num) { struct sembuf sb = {sem_num, 1, 0}; semop(semid, &sb, 1); }

int main() {
    int shmid = shmget(SHM_KEY, sizeof(shared_mem), 0666 | IPC_CREAT);
    shared_mem *shm_ptr = (shared_mem *)shmat(shmid, NULL, 0);
    int semid = semget(SEM_KEY, 2, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1);
    semctl(semid, 1, SETVAL, 0);
    for (int i = 1; i <= 10; i++) {
        sem_wait(semid, 0);
        shm_ptr->number = i;
        printf("Writer wrote: %d\n", i);
        fflush(stdout);
        sem_signal(semid, 1);
        sleep(1);
    }
    shmdt(shm_ptr);
    return 0;
}
