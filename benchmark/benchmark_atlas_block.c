#include <stdio.h>
#include <sys/time.h>

#include "atlas.h"
#include "helper.h"
#include "benchmark_helper.h"

#define MIN_RAND 1
#define MAX_RAND 1000000
#define MIN_N 1024
#define MAX_N 4096
#define ITERATIONS 10
#define STEP (MAX_N - MIN_N) / ITERATIONS

result run(int n, int block_size)
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

    atlas_block_mm(n, block_size, A, B, C);

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

    int block_sizes[11] = {32, 64, 128, 181, 256, 512, 1024, 1402, 2048, 4096};

    for (int i = 0; i < 11; i++)
    {
        int block_size = block_sizes[i];
        result results[ITERATIONS + 1];

        for (int j = 0; j < ITERATIONS + 1; j++)
        {
            results[j] = run(j * STEP + MIN_N, block_size);
            printf("[ATLAS] Blocked matrix multiplication for matrix %d x %d with block size %d took %fs\n", results[j].n, results[j].n, block_size, results[j].elapsed_s);
        }

        char path[256];
        snprintf(path, sizeof(path), "./data/benchmark_atlas_block_%d.dat", block_size);

        export_results(results, ITERATIONS + 1, path);
    }

    return 0;
}