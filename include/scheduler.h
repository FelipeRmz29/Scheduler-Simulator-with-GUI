#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 50
#define MAX_EVENTS 200

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} process_t;

typedef struct {
    int time;
    int pid;
    int duration;
} timeline_event_t;

typedef struct {
    double avg_turnaround_time;
    double avg_waiting_time;
    double avg_response_time;
    double cpu_utilization;
    double throughput;
    double fairness_index;
} metrics_t;

typedef struct {
    int num_queues;
    int quantums[10];
    int boost_interval;
} mlfq_config_t;

void schedule_fifo(process_t *processes, int n, timeline_event_t *timeline, int *timeline_size);
void schedule_sjf(process_t *processes, int n, timeline_event_t *timeline, int *timeline_size);
void schedule_stcf(process_t *processes, int n, timeline_event_t *timeline, int *timeline_size);
void schedule_rr(process_t *processes, int n, int quantum, timeline_event_t *timeline, int *timeline_size);
void schedule_mlfq(process_t *processes, int n, mlfq_config_t *config, timeline_event_t *timeline, int *timeline_size);
void calculate_metrics(process_t *processes, int n, int total_time, metrics_t *metrics);
void generate_report(const char *filename, process_t *processes, int n, metrics_t *metrics);
void run_fifo_example();
#endif
