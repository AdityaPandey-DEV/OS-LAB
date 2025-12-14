#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_KEY 0x1234
#define SEM_KEY 0x5678

typedef struct { int value; } shared_mem;

void sem_wait(int semid, int sem_num) { struct sembuf sb = {sem_num, -1, 0}; if (semop(semid, &sb, 1) == -1) { perror("semop wait failed"); exit(1); } }
void sem_signal(int semid, int sem_num) { struct sembuf sb = {sem_num, 1, 0}; if (semop(semid, &sb, 1) == -1) { perror("semop signal failed"); exit(1); } }

int main() {
    int shmid = shmget(SHM_KEY, sizeof(shared_mem), 0666 | IPC_CREAT);
    if (shmid == -1) { perror("shmget"); exit(1); }
    shared_mem *shm_ptr = (shared_mem *)shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1) { perror("shmat"); exit(1); }
    int semid = semget(SEM_KEY, 2, 0666 | IPC_CREAT);
    if (semid == -1) { perror("semget"); exit(1); }
    for (int i = 1; i <= 10; i++) {
        sem_wait(semid, 1);
        printf("Reader received: %d\n", shm_ptr->value);
        sem_signal(semid, 0);
    }
    shmdt(shm_ptr);
    return 0;
}
