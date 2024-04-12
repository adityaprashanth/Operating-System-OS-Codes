/*the code takes the burst times of n processes as input from 
  the user, calculates the total waiting time, and then computes 
  and prints the average waiting time for those processes.*/

#include <stdio.h>

void main(){
	int n = 0;
	int final = 0;
	int counter = 0;
	int current = 0;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	printf("Enter Burst time:\n");
	for(int i=0; i<n; i++){
		printf("p %d:", i+1);
		scanf("%d", &current);
		final+=counter;
		counter+=current;
	}
	printf("total time is: %f\n", (final*1.0)/n);
}
