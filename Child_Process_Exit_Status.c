/*the code creates a child process, allows it to run for 2 seconds,
  and then exits with status 42. The parent process waits for the child 
  to terminate and prints the exit status of the child process.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int  main()
{
	pid_t pid = fork();

	if(pid == 0)
    {
		sleep(2);
		_exit(42);
	}
    else if(pid > 0)
    {
		siginfo_t info;
		waitid(P_PID, pid, &info, WEXITED);
		printf("Child exited with status: %d\n", info.si_status);
	}
    else
    {
		perror("fork");
		return 1;
	}
	return 0;
}
