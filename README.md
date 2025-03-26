# 🧩 Partition and Knapsack Problem Solving Module 🎒

## 🎯 Module Purpose

This C module is a universal tool solving two complex optimization challenges:

1. **Partition Problem**: 🔀 Splitting numbers into two most equal groups
2. **Knapsack Problem**: 🎒 Optimal item selection within limited capacity

## 🧠 Problem Description

### 🔢 Partition Problem
Given N items with specific weights. Goal: Divide items into two groups with as close weights as possible. 

**Example**: 
- Input: 🏋️ Items with weights 7, 3, 2, 5, 8, 4
- Possible Solution: 
  - 1st Group (14): 7, 3, 4 ⚖️
  - 2nd Group (15): 2, 5, 8 ⚖️
- Difference between groups: 1 🎯

### 🎒 Knapsack Problem
Given N items with weights and values. Goal: Maximize total item value without exceeding backpack capacity.

## 🚀 Module Capabilities

- 🤖 Automatic problem type recognition
- 💡 Dynamic calculation
- 📊 Comprehensive result presentation
- 🔧 Flexible file format support

## 📁 File Format Structure

### 1. 🧩 Partition Problem
```
n           # Number of items
w1 w2 w3 ... wn   # Item weights
```

### 2. 🎒 Knapsack Problem
```
n           # Number of items
w1 w2 w3 ... wn   # Item weights
c           # Backpack capacity
v1 v2 v3 ... vn   # Item values
```

## 💻 Integration Examples

### 1. 🧩 Partition Problem Integration
```c
#include "partition.h"

int main() {
    int weights[] = {10, 20, 15, 5, 25};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 0;  // Automatically calculated

    PartitionResult result = knapsack_or_partition(
        weights, NULL, n, capacity, 1 /* partition mode */
    );

    printf("Difference between groups: %d\n", result.difference);
}
```

### 2. 🎒 Knapsack Problem Integration
```c
#include "partition.h"

int main() {
    int weights[] = {10, 20, 15, 5, 25};
    int values[]  = {2, 3, 4, 5, 1};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 50;

    PartitionResult result = knapsack_or_partition(
        weights, values, n, capacity, 0 /* knapsack mode */
    );

    printf("Maximum value: %d\n", result.sum1);
}
```

## 🚧 Limitations and Logic

### 🔢 Maximum Number of Elements: 100
- 📊 Dynamic programming complexity O(n²)
- 💾 Limited memory and time consumption
- ⏱️ Ensures solution speed up to 1 second

### 🎒 Maximum Backpack Capacity: 1000
- 🛡️ Prevents number overflow
- 💾 Limits memory usage
- 🏗️ Supports algorithm stability

### 🔢 Only Positive Integers
- 🧩 Simplifies optimization logic
- 🌍 Fits most practical problems
- 🚫 Avoids additional checks

## 🛠️ Installation and Compilation Instructions

1. 📂 Copy `partition.h` and `partition.c` to your project
2. 🔧 Add module to compilation process
3. 📋 Include `#include "partition.h"` in your code

## 📄 License

Open-source module for academic projects. 🎓

## 👥 Authors

Module created as an academic project to practically apply optimization algorithms. 🚀
