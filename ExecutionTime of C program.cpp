#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
    // Start time
    clock_t startTime = clock();

    // Code block to measure (e.g., calculating powers in a loop)
    for (int i = 0; i < 10000000; i++) {
        pow(i, 2);
    }

    // End time
    clock_t endTime = clock();

    // Execution time in clock ticks
    double exeTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Print the execution time in seconds, milliseconds, and nanoseconds
    printf("Execution time: %f seconds\n", exeTime);
    printf("Execution time: %f milliseconds\n", exeTime * 1000);
    printf("Execution time: %f nanoseconds\n", exeTime * 1e9);

    return 0;
}

