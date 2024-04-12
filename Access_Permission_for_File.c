/*The provided C program checks the access permissions for a file specified as a command-line argument*/

/*
While running in the terminal :

To run normally (op is invalid cause you are not reading a file) :
gcc Access_Permission_for_File.c -o q
./q

to read a file : 
gcc Access_Permission_for_File.c -o q
./q file_to_read.txt
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2)
        printf("invalid file \n");

    if (access(argv[1], R_OK) < 0)
        printf("read access error for %s\n", argv[1]);

    else 
        printf("read access OK\n");
    
    if (access(argv[1], W_OK) < 0)
        printf("write access error for %s\n", argv[1]);

    else 
        printf("write access OK\n");

    if (access(argv[1], X_OK) < 0)
        printf("exec access error for %s\n", argv[1]);

    else
        printf("exec access OK\n");

    if (fd - open(argv[1], O_RDONLY) < 0)
        printf("open error for %s\n", argv[1]);

    else
        printf("opened for reading\n");

    close(fd);
    exit(0);
}

/*
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int fd;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (access(argv[1], R_OK) < 0) {
        printf("read access error for %s\n", argv[1]);
    } else {
        printf("read access OK\n");
    }
    
    if (access(argv[1], W_OK) < 0) {
        printf("write access error for %s\n", argv[1]);
    } else {
        printf("write access OK\n");
    }

    if (access(argv[1], X_OK) < 0) {
        printf("exec access error for %s\n", argv[1]);
    } else {
        printf("exec access OK\n");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("open error for %s\n", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        printf("opened for reading\n");
    }

    close(fd);
    exit(EXIT_SUCCESS);
}

*/