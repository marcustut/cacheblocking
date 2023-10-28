#include <sys/time.h>
#include <string.h>

#include "manual.h"
#include "atlas.h"
#include "helper.h"
#include "test_helper.h"

#define N 1024
#define BLOCK_SIZE 32
#define MIN 1
#define MAX 1000000
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

int main(void)
{
    // Use current time as seed for random generator
    srand(time(0));

    // Allocate memory for the matrices
    double *A = malloc(N * N * sizeof(double));
    double *B = malloc(N * N * sizeof(double));
    double *C = malloc(N * N * sizeof(double));
    double *D = malloc(N * N * sizeof(double));
    if (!A || !B || !C || !D)
    {
        fprintf(stderr, "Out of memory, reduce dimension n\n");
        return -1;
    }

    // Initialise the matrices with some random values
    init_random_square_matrix(N, A, MIN, MAX);
    init_random_square_matrix(N, B, MIN, MAX);

    // Run matrix multiplication
    atlas_block_mm(N, BLOCK_SIZE, A, B, C);
    manual_mm(N, A, B, D);

    // Compare the two matrices
    compare_matrix(N, C, D);
    printf("[PASSED] %s\n", __FILENAME__);

    free(A);
    free(B);
    free(C);
    free(D);
}