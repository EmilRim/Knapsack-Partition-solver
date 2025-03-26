#ifndef PARTITION_H
#define PARTITION_H

#define MAX_ITEMS 100
#define MAX_CAPACITY 10000

typedef struct {
    int sum1;           // Sum of first subset
    int sum2;           // Sum of second subset
    int difference;     // Difference between subset sums
    int subset1[MAX_ITEMS];  // Elements in first subset
    int subset2[MAX_ITEMS];  // Elements in second subset
    int subset1_size;   // Number of elements in first subset
    int subset2_size;   // Number of elements in second subset
} PartitionResult;

PartitionResult knapsack_or_partition(int *weights, int *values, int n, int capacity, int is_partition);
void read_input(const char *filename, int *weights, int *values, int *n, int *capacity, int *is_partition);

#endif
