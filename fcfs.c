#include<stdio.h>
#include<stdlib.h>

int* calculate_completion_time(int *arrival_time, int *burst_time, int n);
int* calculate_waiting_time(int *arrival_time, int *completion_time, int *burst_time, int n);
int* calculate_turnaround_time(int *arrival_time, int *completion_time, int n);
void display_result(int *arrival_time, int *burst_time, int *waiting_time, int *completion_time, int *turnaround_time, int n);

int main()
{
	printf("Enter number of processes: ");
	int n;
	scanf("%d", &n);
	int* arrival_time = (int*)malloc(sizeof(int)*n);
	int* burst_time = (int*)malloc(sizeof(int)*n);
	int* waiting_time;
	int* turnaround_time;
	int* completion_time;
	printf("Enter arrival time for the processes in a sorted order: ");
	for(int i=0; i<n; i++){ scanf("%d", &arrival_time[i]); }
	printf("Enter burst time for the processes: ");
	for(int i=0; i<n; i++){ scanf("%d", &burst_time[i]); }
	completion_time = calculate_completion_time(arrival_time, burst_time, n);
	waiting_time = calculate_waiting_time(arrival_time, completion_time, burst_time, n);
	turnaround_time = calculate_turnaround_time(arrival_time, completion_time, n);
	display_result(arrival_time, burst_time, waiting_time, completion_time, turnaround_time, n);
}




int* calculate_completion_time(int *arrival_time, int *burst_time, int n)
{
	int* completion_time = (int*)malloc(sizeof(int)*n);
	completion_time[0] = burst_time[0] + arrival_time[0];
	for(int i=1; i<n; i++)
		completion_time[i] = completion_time[i-1] + burst_time[i];
	return completion_time;
}

int* calculate_waiting_time(int *arrival_time, int *completion_time, int *burst_time, int n)
{
	int* waiting_time = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++){
		waiting_time[i] = completion_time[i] - arrival_time[i] - burst_time[i];
		if(waiting_time[i] < 0){
			waiting_time[i] = 0;
		}
	}
	return waiting_time;
}

int* calculate_turnaround_time(int *arrival_time, int *completion_time, int n)
{
	int* turnaround_time = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++){
		turnaround_time[i] = completion_time[i] - arrival_time[i];
		if(turnaround_time[i] < 0){
			turnaround_time[i] = 0;
		}
	}
	return turnaround_time;
}

void display_result(int *arrival_time, int *burst_time, int *waiting_time, int *completion_time, int *turnaround_time, int n)
{
	printf("%s%20s%20s%20s%20s%20s\n", "Process", "Arrival Time", "Burst Time", "Waiting Time", "Completion Time", "Turnaround Time");
	for(int i=0; i<n; i++)
	{
		printf("%d%20d%20d%20d%20d%20d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], completion_time[i], turnaround_time[i]);
	}
	float average_waiting=0;
	for(int i=0;i < n; i++){
		average_waiting = average_waiting + waiting_time[i];
	}
	printf("Average waiting time = %f",average_waiting);
}