#include <stdio.h>
#include <sys/time.h>

#include "blas.h"
#include "helper.h"
#include "benchmark_helper.h"

#define MIN_RAND 1
#define MAX_RAND 1000000
#define MIN_N 1024
#define MAX_N 4096
#define ITERATIONS 10
#define STEP (MAX_N - MIN_N) / ITERATIONS

result run(int n)
{
    // Allocate memory for the matrices
    double *A = malloc(n * n * sizeof(double));
    double *B = malloc(n * n * sizeof(double));
    double *C = malloc(n * n * sizeof(double));
    if (!A || !B || !C)
    {
        fprintf(stderr, "Out of memory, reduce dimension n\n");
        exit(-1);
    }

    // Initialise the matrices with some random values
    init_random_square_matrix(n, A, MIN_RAND, MAX_RAND);
    init_random_square_matrix(n, B, MIN_RAND, MAX_RAND);

    struct timeval start, end;
    struct timezone tz;

    gettimeofday(&start, &tz);

    blas_mm(n, A, B, C);

    gettimeofday(&end, &tz);

    // Calculate the elapsed time in seconds
    double elapsed_s = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) * 1.e-6;

    // Deallocate the memory
    free(A);
    free(B);
    free(C);

    return (result){n, elapsed_s};
}

int main(void)
{
    // Use current time as seed for random generator
    srand(time(0));

    result results[ITERATIONS + 1];

    for (int i = 0; i <= ITERATIONS; i++)
    {
        results[i] = run(i * STEP + MIN_N);
        printf("[BLAS] Non blocked matrix multiplication for matrix %d x %d took %fs\n", results[i].n, results[i].n, results[i].elapsed_s);
    }

    export_results(results, ITERATIONS + 1, "./data/benchmark_blas_non_block.dat");

    return 0;
}