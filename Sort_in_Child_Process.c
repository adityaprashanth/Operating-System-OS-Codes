/*create a global array with values {1, 6, 2, 4, 5, 8, 9, 0}. Sort the same within
  the child process, and display the values in the parent process*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int data[] = {1, 6, 2, 4, 5, 8, 9, 0};
int n = sizeof(data) / sizeof(data[0]);
void bubbleSort() 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (data[j] > data[j + 1]) 
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
int main() 
{
    printf("parent process input is :");
    for (int i = 0; i < n; i++) 
        {
            printf("%d ", data[i]);
        }
        printf("\n");
    
    pid_t pid = fork();
    if (pid == 0)         // Child process
    {
        printf("child process output is :");
        bubbleSort();
    } 
    else if (pid > 0)      // Parent process
    {
        printf("child process output is :");
        wait(NULL);
        for (int i = 0; i < n; i++) 
        {
            printf("%d ", data[i]);
        }
        printf("\n");
    } 
    else 
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}