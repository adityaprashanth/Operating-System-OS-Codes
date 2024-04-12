/*the creation of a parent and a child process using fork(). 
  Both processes execute similar loops but perform different 
  operations on a shared variable y, showcasing the concurrent 
  execution of parent and child processes.*/

#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t p1, p2;
	int n;
	
	int i , y=0;

	p1=fork();

	if(p1>0) // parent process
	{
		for(i=0; i<5; i++)
		{		
			sleep(i);

			y= y-1;

			printf("this is parent, process id = %d, y = %d\n", getpid(), y);
		}
	}
	else if(p1==0) //child process
	{
		for(i=0; i<5; i++)
		{		
			sleep(i);

			y= y + 1;

			printf("this is child, process id = %d,parent process id = %d y = %d\n", getpid(), getppid(), y);
		}
	}
	else
	{
		printf("frok creation failed!!");
	}
}