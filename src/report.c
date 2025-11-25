#include "../include/scheduler.h"
#include <stdio.h>

void generate_report(const char *filename, process_t *processes, int n, metrics_t *metrics) {
    FILE *file = fopen(filename, "w");
    if (!file) return;

    fprintf(file, "# Scheduler Performance Report\n\n");
    fprintf(file, "## Process Set\n\n");
    fprintf(file, "| PID | Arrival | Burst | Priority |\n");
    fprintf(file, "|-----|---------|-------|----------|\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "| %d   | %d       | %d     | %d        |\n",
                processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }
    fprintf(file, "\n## Metrics\n\n");
    fprintf(file, "- Avg Turnaround Time: %.2f\n", metrics->avg_turnaround_time);
    fprintf(file, "- Avg Waiting Time: %.2f\n", metrics->avg_waiting_time);
    fprintf(file, "- Avg Response Time: %.2f\n", metrics->avg_response_time);
    fprintf(file, "- CPU Utilization: %.2f%%\n", metrics->cpu_utilization);
    fprintf(file, "- Throughput: %.2f\n", metrics->throughput);
    fprintf(file, "- Fairness Index: %.2f\n", metrics->fairness_index);

    fclose(file);
}
