/*This code is typically used for privilege escalation or to temporarily change 
  the user ID of a process to perform certain privileged operations and then revert 
  back to the original user ID. However, it's important to note that changing user IDs 
  should be done with caution, as it can introduce security vulnerabilities if not used properly.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    int rv = 0;
    
    printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
    
    rv = setuid(1000);

    if(rv<0){
        printf("error setting uid\n");
    }

    rv = seteuid(1000);

    if(rv<0){
        printf("error setting uid\n");
    }

    printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());

    exit(0);
}