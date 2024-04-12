/* the creation of a child process using fork() and the synchronization of 
   the parent and child processes using wait().*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		printf("fork lifted");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child process\n");
		printf("id of parent = %d, id of child = %d\n", getppid(), getppid());
	}
	else
	{
		wait(NULL);
		printf("parent process\n");
		printf("id of parent = %d, id of child = %d\n", getppid(), pid);
	}
	return 0;
}
