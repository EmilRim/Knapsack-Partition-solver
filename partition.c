#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partition.h"

// DP table
static int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

// Function to reconstruct the subset from DP table
static void reconstruct_subset(int *weights, int n, int target, int *subset, int *subset_size)
{
    *subset_size = 0;
    for (int i = n, w = target; i > 0 && w > 0; i--)
    {
        if (dp[i - 1][w] != dp[i][w])
        { // Item was included in the subset
            subset[*subset_size] = weights[i - 1];
            (*subset_size)++;
            w -= weights[i - 1];
        }
    }
}

// Function to solve Knapsack or Partition problem
PartitionResult knapsack_or_partition(int *weights, int *values, int n, int capacity, int is_partition)
{
    PartitionResult result = {.sum1 = 0, .sum2 = 0, .difference = 0};
    memset(dp, 0, sizeof(dp));

    // Calculate total sum for partition problem
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += weights[i];
    }

    // For partition problem, adjust capacity if needed
    if (is_partition) {
        capacity = total_sum / 2;
    }

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
            {
                if (!is_partition)
                { // Knapsack
                    dp[i][w] = values ? (dp[i - 1][w] > values[i - 1] + dp[i - 1][w - weights[i - 1]]
                                             ? dp[i - 1][w]
                                             : values[i - 1] + dp[i - 1][w - weights[i - 1]])
                                      : 0;
                }
                else
                { // Partition
                    dp[i][w] = (dp[i - 1][w] || (w == weights[i - 1]) || dp[i - 1][w - weights[i - 1]]);
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    if (!is_partition)
    {
        result.sum1 = dp[n][capacity]; // Max Knapsack Value
    }
    else
    {
        // Find the closest possible subset sum that minimizes the difference
        int closest_sum = 0;
        int min_difference = total_sum;

        // Try all possible subset sums
        for (int w = 0; w <= capacity; w++)
        {
            if (dp[n][w])
            {
                int current_difference = abs(total_sum - 2 * w);
                if (current_difference < min_difference)
                {
                    min_difference = current_difference;
                    closest_sum = w;
                }
            }
        }

        result.sum1 = closest_sum;
        result.sum2 = total_sum - closest_sum;
        result.difference = abs(result.sum2 - result.sum1);

        int used[MAX_ITEMS] = {0};
        int s1_size = 0;

        // Reconstruct Subset 1
        reconstruct_subset(weights, n, closest_sum, result.subset1, &s1_size);

        // Mark used items in Subset 1
        for (int i = 0; i < s1_size; i++)
        {
            used[result.subset1[i]]++;
        }

        // Reconstruct Subset 2 (remaining items)
        int s2_size = 0;
        for (int i = 0; i < n; i++)
        {
            if (used[weights[i]] > 0)
            {
                used[weights[i]]--; // This item was used in Subset 1, don't add it to Subset 2
            }
            else
            {
                result.subset2[s2_size++] = weights[i]; // This item is added to Subset 2
            }
        }
        result.subset2_size = s2_size;
        result.subset1_size = s1_size;
    }

    return result;
}

// Function to read input from file
void read_input(const char *filename, int *weights, int *values, int *n, int *capacity, int *is_partition)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        exit(1); // Error should be handled outside partition.c
    }

    fscanf(file, "%d", n); // Read number of items

    for (int i = 0; i < *n; i++)
    {
        fscanf(file, "%d", &weights[i]);
    }

    if (fscanf(file, "%d", capacity) == 1)
    { // Knapsack Mode
        *is_partition = 0;
        for (int i = 0; i < *n; i++)
        {
            fscanf(file, "%d", &values[i]);
        }
    }
    else
    { // Partition Mode
        *is_partition = 1;
        *capacity = 0;
        for (int i = 0; i < *n; i++)
        {
            *capacity += weights[i];
        }
        *capacity /= 2; // Target subset sum
    }

    fclose(file);
}
