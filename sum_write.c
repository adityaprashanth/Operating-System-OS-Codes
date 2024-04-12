// Program to demo shared memory. This program will create a shared memory segment and write to it

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    void *shared_memory;
    char buff[100] = "";
    int shmid = 0;
    // Creates a shared memory segment with key 2345, size 1024 bytes and permissions 0666
    // IPC_CREAT flag is used to create a new shared memory segment if it does not exist. 0666 are the permissions for the shared memory segment
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0); // Process attached to shared memory segment
    printf("Process attached at %p\n", shared_memory); // Print the address where shared memory segment is attached to the process
    printf("Enter data to write into shared memory segment:\n");
    // get the data from the user
    read(0, buff, 100);
    // copy the data to the shared memory segment
    strcpy(shared_memory, buff);
    sleep(100); 
    shmdt(shared_memory); // Process detached from shared memory segment
    return 0;
}