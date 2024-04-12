/*the creation of a parent process, a child process, and a grandchild process 
  using fork(). Each process executes different blocks of code based on the return 
  value of fork(), resulting in a hierarchy of processes. Additionally, it manipulates 
  and prints the value of y within each process to demonstrate the flow of execution.*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t p1, p2;
	
	int y=0 , pid;

	p1=fork();
	
	if(p1>0) // parent process
	{
		wait(NULL);
		y = y - 1;
		printf("this is parent, process id = %d\n",getpid());
	} 
	else if(p1==0) //child process
	{
		p2=fork();

		if(p2 > 0)
		{
            wait(NULL);
		}
		else if(p2==0)
		{
			y = y + 5;

			printf("this is grandchild, process id = %d,parent process id = %d\n", getpid(), getppid());
			printf("addition of two numbers = %d\n", y);

			exit(0);
		}

		y = y + 1;

		printf("this is child, process id = %d,parent process id = %d\n", getpid(), getppid());
		if(y%2){
			printf("the number is not divisible by 2\n");
		}else{
			printf("the number is divisible by 2\n");
		}
		exit(0);
	}
	else // fork failed
	{
		printf("frok creation failed!!");
	}
	
	printf("Good Morining!\n");
}