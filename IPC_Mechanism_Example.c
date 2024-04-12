/*This code creates a shared memory segment using System V IPC
  (Inter-Process Communication) mechanism in Unix-like operating systems.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    void *shared_memory;
    char buff[100] = "";
    int shmid = 0;

    // Generate a unique key for shared memory
    key_t key = ftok("/tmp", 'R');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a new shared memory segment
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the address space of the calling process
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory segment attached at address %p\n", shared_memory);

    // Detach the shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
