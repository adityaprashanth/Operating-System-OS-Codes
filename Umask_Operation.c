/*umask operation*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc, char *argv[])
{
    umask(0);
    umask(S_IROTH | S_IWOTH);

    if (creat("1.txt", RWRWRW) < 0)
        printf("Error creating the file\n");

    exit(0);
}

/*
What to give in terminal :

gcc example16.c -o q 
./q
umask -S
output u=rwx,g=rx,o=rx

umask 022
umask -S
output u=rwx,g=rx,o=rx

umask 027
umask -S
output u=rwx,g=rx,o=

umask 000
umask -S
output u=rwx,g=rwx,o=rwx

umask 777
umask -S
output u=,g=,o=

umask 000
umask -S
output u=rwx,g=rwx,o=rwx
*/