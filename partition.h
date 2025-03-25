#ifndef PARTITION_H
#define PARTITION_H

#define MAX_ITEMS 1000     // Maximum number of items
#define MAX_CAPACITY 10000 // Maximum capacity

typedef struct {
    int subset1[MAX_ITEMS];
    int subset2[MAX_ITEMS];
    int sum1;
    int sum2;
    int difference;
} PartitionResult;

void read_input(const char *filename, int *weights, int *values, int *n, int *capacity, int *is_partition);
PartitionResult knapsack_or_partition(int *weights, int *values, int n, int capacity, int is_partition);
int read_input_stdin(int *weights, int *values, int *n, int *capacity, int *is_partition);
void run_test_with_params(int *weights, int *values, int n, int capacity, int is_partition, const char *mode, int timeout);

#endif
