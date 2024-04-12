/*the code implements the FIFO page replacement algorithm and 
  calculates the number of page faults based on the given reference 
  string and number of frames.*/
  
#include <stdio.h>

int main(){

    int i, j, k, f, pf=0, count=0, rs[25], m[10], n;

    printf("Enter the length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for(i=0; i<n; i++)
        scanf("%d", &rs[i]);
    
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for(i=0; i<f; i++)
        m[i] = -1;

    printf("Page replacement process: \n");
    for(i=0; i<n; i++){
        for(k=0; k<f; k++){
            if(m[k] == rs[i])
                break;
        }

        if(k==f){
            m[count++] = rs[i];
            pf++;
        }

        for(j=0; j<f; j++)
            printf("\t%d", m[j]);

        if(k==f)
            printf("\tPF No. %d", pf);
        
        printf("\n");

        if(count == f)
            count = 0;
    }
    printf("The number of page faults using FIFO are %d\n", pf);
}