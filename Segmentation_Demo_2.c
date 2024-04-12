/*this code demonstrates how to use semaphores to ensure that only one thread
  can access the shared variable at a time, preventing race conditions. The threads 
  increment and decrement the shared variable in a synchronized manner, and the final 
  value of the shared variable is printed at the end.*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_THREADS 2
int shared_variable = 0;
sem_t semaphore;
void *increment(void *arg) 
{
    int i;
    for (i = 0; i < 5; i++) {
        sem_wait(&semaphore);
        shared_variable++;
        printf("Thread 1: Incremented, value = %d\n", shared_variable);
        sem_post(&semaphore); 
    }
    pthread_exit(NULL);
}
void *decrement(void *arg) 
{
    int i;
    for (i = 0; i < 5; i++) {
        sem_wait(&semaphore); 
        shared_variable--;
        printf("Thread 2: Decremented, value = %d\n", shared_variable);
        sem_post(&semaphore); 
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    sem_init(&semaphore, 0, 1);
    pthread_create(&threads[0], NULL, increment, NULL);
    pthread_create(&threads[1], NULL, decrement, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    sem_destroy(&semaphore); 
    printf("Final shared variable value: %d\n", shared_variable);
    return 0;
}
