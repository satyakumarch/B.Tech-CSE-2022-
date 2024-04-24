#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

struct Process {
    char name[20];
    int arrival_time;
    int execution_time;
    int priority;
    int remaining_time;
};

int main() {
    char filename[50];
    int time_slice;
    
    printf("Enter the filename containing process data: ");
    scanf("%s", filename);
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or unable to open the file.\n");
        return 1;
    }
    
    printf("Enter the time slice size: ");
    scanf("%d", &time_slice);
    
    struct Process processes[MAX_PROCESSES];
    int num_processes = 0;
    
    while (fscanf(file, "%s %d %d %d", processes[num_processes].name, &processes[num_processes].arrival_time, &processes[num_processes].execution_time, &processes[num_processes].priority) == 4) {
        processes[num_processes].remaining_time = processes[num_processes].execution_time;
        num_processes++;
    }
    
    fclose(file);
    
    int total_turnaround_time = 0;
    
    int current_time = 0;
    int index = 0;
    int completed = 0;
    
    while (completed < num_processes) {
        if (processes[index].remaining_time > 0) {
            int time_executed = (processes[index].remaining_time < time_slice) ? processes[index].remaining_time : time_slice;
            processes[index].remaining_time -= time_executed;
            current_time += time_executed;
            
            printf("%s: %d\n", processes[index].name, current_time);
            
            if (processes[index].remaining_time == 0) {
                total_turnaround_time += current_time - processes[index].arrival_time;
                completed++;
            }
        }
        
        index = (index + 1) % num_processes;
    }
    
    double average_turnaround_time = (double)total_turnaround_time / num_processes;
    printf("Average Turnaround Time: %.2lf\n", average_turnaround_time);
    
    return 0;
}
output
Enter the filename containing process data: processes.txt
Enter the time slice size: 2
P1: 2
P2: 4
P3: 6
P4: 8
P1: 10
P2: 12
P3: 14
P1: 16
P3: 18
P3: 20
Average Turnaround Time: 10.75
