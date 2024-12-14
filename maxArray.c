#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int *array = NULL;
    int local_max = 0, global_max = 0;

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
            array[i] = rand() % 1000; // generate numbers between 0 and 999
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

    // Calculate local max
    for (int i = 0; i < ARRAY_SIZE / size; i++) {
        if (local_array[i] > local_max) {
            local_max = local_array[i];
        }
    }

    // Find global max using MPI_Reduce
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    // Print result on rank 0
    if (rank == 0) {
        printf("Global max: %d\n", global_max);
        free(array); // Free allocated memory
    }

    // Free allocated memory for local_array
    free(local_array);

    // Finalize MPI environment
    MPI_Finalize();

    return 0;
}

