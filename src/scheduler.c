#include "../include/scheduler.h"
#include <stdio.h>

// Función para probar FIFO desde la GUI o tests
void run_fifo_example() {
    process_t processes[] = {
        {1, 0, 5, 1, 5, -1, -1, -1, -1, -1},
        {2, 1, 3, 2, 3, -1, -1, -1, -1, -1},
        {3, 2, 8, 1, 8, -1, -1, -1, -1, -1}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    timeline_event_t timeline[MAX_EVENTS];
    int timeline_size = 0;

    schedule_fifo(processes, n, timeline, &timeline_size);

    int total_time = timeline[timeline_size - 1].time + timeline[timeline_size - 1].duration;
    metrics_t metrics;
    calculate_metrics(processes, n, total_time, &metrics);

    printf("FIFO Scheduling Results:\n");
    printf("Avg Turnaround Time: %.2f\n", metrics.avg_turnaround_time);
    printf("Avg Waiting Time: %.2f\n", metrics.avg_waiting_time);
    printf("Avg Response Time: %.2f\n", metrics.avg_response_time);
    printf("CPU Utilization: %.2f%%\n", metrics.cpu_utilization);
    printf("Throughput: %.2f processes/unit time\n", metrics.throughput);
    printf("Fairness Index: %.2f\n", metrics.fairness_index);
}
