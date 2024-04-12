/*the code takes input for the burst time of each process, 
  calculates the waiting time for each process based on their 
  burst time, computes the average waiting time, and prints the result.*/

//FCFS -> sheduling process

#include <stdio.h>

float average(int* wait, int n){
	int counter = 0;
	for(int i=0; i<n; i++){
		counter+=wait[i];
	}
	return counter*1.0/n;
}

int main() {
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);    

	int time[n], wait[n];

	printf("Enter the burst time for each process:\n");

	for(int i=0; i<n; i++){
		printf("Process %d: ", i + 1);
		scanf("%d", &time[i]);
	}

	int counter = 0;
	for(int i=0; i<n; i++){
		wait[i] = counter;
		counter += time[i];
	}
	
	printf("The average waiting time is: %f\n", average(wait, n));
	
    	return 0;
}