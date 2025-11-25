#include "../include/algorithms.h"
#include <stdlib.h>

void schedule_fifo(process_t *processes, int n, timeline_event_t *timeline, int *timeline_size) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                process_t temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;
        timeline[*timeline_size].time = current_time;
        timeline[*timeline_size].pid = processes[i].pid;
        timeline[*timeline_size].duration = processes[i].burst_time;
        (*timeline_size)++;
        processes[i].start_time = current_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}
