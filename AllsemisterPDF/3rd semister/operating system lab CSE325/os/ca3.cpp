#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Process {
    char name[20];
    int arrival_time;
    int execution_time;
    int priority;
};

int main() {
   
    char filename[100];
    printf("Enter the file name:");
    scanf("%s", filename);

    
    printf("\n");
    int time_slice;
    printf("Enter the time slice size: ");
    scanf("%d", &time_slice);
     printf("\n");

    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n\n");
        return 1;
    }

    
    int num_processes;
    fscanf(file, "%d", &num_processes);

    struct Process *processes = (struct Process *)malloc(num_processes * sizeof(struct Process));

    for (int i = 0; i < num_processes; i++) {
        fscanf(file, "%s %d %d %d", processes[i].name, &processes[i].arrival_time,
		 &processes[i].execution_time, &processes[i].priority);
    }

    fclose(file);

  
    int total_time = 0;
    int *remaining_time = (int *)malloc(num_processes * sizeof(int));
    int *waiting_time = (int *)malloc(num_processes * sizeof(int));
    int *turnaround_time = (int *)malloc(num_processes * sizeof(int));

    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i].execution_time;
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    int completed_processes = 0; 
    int time_quantum = time_slice;
    int current_process = 0;

    while (completed_processes < num_processes) {
        if (remaining_time[current_process] <= time_quantum && remaining_time[current_process] > 0) {
            total_time += remaining_time[current_process];
            remaining_time[current_process] = 0;
            turnaround_time[current_process] = total_time - processes[current_process].arrival_time;
            completed_processes++;
        } else if (remaining_time[current_process] > 0) {
            total_time += time_quantum;
            remaining_time[current_process] -= time_quantum;
        }

        for (int i = 0; i < num_processes; i++) {
            if (i != current_process && processes[i].arrival_time <= total_time && remaining_time[i] > 0) {
                waiting_time[i] += total_time - processes[i].arrival_time;
            }
        }

        current_process = (current_process + 1) % num_processes;
    }

  
    printf("Process\tTurnaround Time\tWaiting Time:\n\n");
    double total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t\t%d\n\n", processes[i].name, turnaround_time[i], waiting_time[i]);
        total_turnaround_time += turnaround_time[i];
    }

    
    double average_turnaround_time = total_turnaround_time / num_processes;
    printf("Average Turnaround Time: %.2lf\n\n", average_turnaround_time);

   
    free(processes);
    free(remaining_time);
    free(waiting_time);
    free(turnaround_time);

    return 0;
}
//output
//Enter the file name:os.txt
//
//Enter the time slice size: 2
//
//Process Turnaround Time Waiting Time:
//
//p1      24              122
//
//p2      20              74
//
//p3      12              26
//
//p4      24              198
//
//Average Turnaround Time: 20.00


