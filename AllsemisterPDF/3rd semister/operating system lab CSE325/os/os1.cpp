#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    char name[20];
    int arrival_time;
    int execution_time;
    int priority;
    int remaining_time;
};

// Function to simulate Round Robin scheduling
void roundRobin(struct Process processes[], int n, int time_slice) {
    int total_time = 0;
    int total_turnaround_time = 0;
    int total_wait_time = 0;

    int *completion_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    if (!completion_time || !turnaround_time) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].execution_time;
        completion_time[i] = 0;
        turnaround_time[i] = 0;
    }

    int currentTime = 0;
    int remaining_processes = n;

    // Perform Round Robin scheduling
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int time_executed = time_slice < processes[i].remaining_time ? time_slice : processes[i].remaining_time;
                currentTime += time_executed;
                processes[i].remaining_time -= time_executed;

                if (processes[i].remaining_time == 0) {
                    remaining_processes--;

                    // Calculate completion time, turnaround time, and wait time
                    completion_time[i] = currentTime;
                    turnaround_time[i] = completion_time[i] - processes[i].arrival_time;

                    total_turnaround_time += turnaround_time[i];
                    total_wait_time += turnaround_time[i] - processes[i].execution_time;
                }
            }
        }
    }

    // Print the results for each process
    printf("Process\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\n", processes[i].name, turnaround_time[i], turnaround_time[i] - processes[i].execution_time);
    }

    // Calculate and print the average turnaround time
    float average_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);

    // Clean up allocated memory
    free(completion_time);
    free(turnaround_time);
}

int main() {
    char filename[100];
    int time_slice;
    printf("Enter the file name: ");
    scanf("%s", filename);
    printf("Enter the time slice size: ");
    scanf("%d", &time_slice);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or unable to open!\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    struct Process processes[n];

    // Read process data from the file
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %d %d %d", processes[i].name, &processes[i].arrival_time, &processes[i].execution_time, &processes[i].priority);
    }

    fclose(file);

    // Call the Round Robin scheduling function
    roundRobin(processes, n, time_slice);

    return 0;
}

