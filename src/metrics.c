#include "../include/metrics.h"
#include <math.h>

void calculate_metrics(process_t *processes, int n, int total_time, metrics_t *metrics) {
    double sum_tat = 0, sum_wt = 0, sum_rt = 0;
    double sum_xi = 0, sum_xi2 = 0;
    int busy_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        processes[i].response_time = processes[i].start_time - processes[i].arrival_time;
        sum_tat += processes[i].turnaround_time;
        sum_wt += processes[i].waiting_time;
        sum_rt += processes[i].response_time;
        sum_xi += processes[i].turnaround_time;
        sum_xi2 += processes[i].turnaround_time * processes[i].turnaround_time;
        busy_time += processes[i].burst_time;
    }
    metrics->avg_turnaround_time = sum_tat / n;
    metrics->avg_waiting_time = sum_wt / n;
    metrics->avg_response_time = sum_rt / n;
    metrics->cpu_utilization = (busy_time / (double)total_time) * 100;
    metrics->throughput = n / (double)total_time;
    metrics->fairness_index = (sum_xi * sum_xi) / (n * sum_xi2);
}

