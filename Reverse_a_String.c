/*Using pipes, reverse a string. One process takes in the string
  as input and writes it to a pipe. The other process reads from the
  pipe and reverses the string.*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_STRING_SIZE 100
void reverse_string(char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int main() 
{
    int fd[2];
    pid_t pid;
    char input_str[MAX_STRING_SIZE];
    printf("Enter a string: ");
    fgets(input_str, MAX_STRING_SIZE, stdin);
    input_str[strlen(input_str) - 1] = '\0';
    pipe(fd);
    pid = fork();
    if (pid > 0) 
    {
        close(fd[0]);
        write(fd[1], input_str, strlen(input_str) + 1);
        close(fd[1]);
    } 
    else if (pid == 0) 
    {
        close(fd[1]);
        char output_str[MAX_STRING_SIZE];
        read(fd[0], output_str, MAX_STRING_SIZE);
        reverse_string(output_str);
        printf("Reversed string: %s\n", output_str);
        close(fd[0]);
    }
    return 0;
}
