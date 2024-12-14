#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int *array = NULL;
    int local_sum = 0, global_sum = 0;
    double local_avg = 0.0, global_avg = 0.0;

    // Initialize MPI environment
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Only rank 0 should allocate and initialize the array
    if (rank == 0) {
        srand(time(NULL));
        array = (int*) malloc(ARRAY_SIZE * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = rand() % 100;
        }
    }

    // Allocate memory for local array
    int *local_array = (int*) malloc(ARRAY_SIZE / size * sizeof(int));
    if (local_array == NULL) {
        printf("Memory allocation failed.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Scatter the array to all processes
    MPI_Scatter(array, ARRAY_SIZE / size, MPI_INT, local_array, ARRAY_SIZE / size, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local sum
    for (int i = 0; i < ARRAY_SIZE / size; i++) {
        local_sum += local_array[i];
    }

    // Sum all local sums to get global sum
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calculate local average
    local_avg = (double)local_sum / (ARRAY_SIZE / size);

    // Sum all local averages to get global average
    MPI_Reduce(&local_avg, &global_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print result on rank 0
    if (rank == 0) {
        global_avg /= ARRAY_SIZE; // Divide by total array size, not number of processes
        printf("Global sum: %d\n", global_sum);
        printf("Global average: %.2f\n", global_avg);
        free(array); // Free allocated memory
    }

    // Free allocated memory for local_array
    free(local_array);

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}

