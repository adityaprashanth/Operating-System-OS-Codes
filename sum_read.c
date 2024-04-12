// Program to demo shared memory. This program reads from shared memory segment.
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
int main(){
    void *shared_memory;
    char buff[10] = "";
    int shmid = 0;
    shmid = shmget((key_t)2345, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0); // Process attached to shared memory segment
    printf("Process attached at %p\n", shared_memory); // Print the address where shared memory segment is attached to the process
    printf("Data read from shared memory is: %s\n", (char *)shared_memory);
    shmdt(shared_memory); // Process detached from shared memory segment
    return 0;
}
