/*The code essentially creates a named pipe, 
  reads input messages from the user, and writes 
  them to the named pipe (FIFO) for communication with other processes.*/

//program to demo FIFO - write 
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
    #define BUFFER_SIZE 100
int main()
{
    int fd;
    char buff[BUFFER_SIZE]="";

    //FIFO file path
    char myfifo[BUFFER_SIZE]= "/tmp/myfifo";

    printf("ENter th messages top be passed\n");
    read(0, buff, BUFFER_SIZE);

    //creating a named file(FIFO)
    mkfifo(myfifo,0666);

    fd = open(myfifo,O_WRONLY);

    //Write the input to FIFO and clode it
    write(fd, buff,strlen(buff)+1);
    close(fd);
}