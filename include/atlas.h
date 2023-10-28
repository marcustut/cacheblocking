#include <cblas.h>

#define ATLAS_ALPHA 1.0
#define ATLAS_BETA 1.0

void atlas_mm(int n, double *A, double *B, double *C)
{
    ATL_dgemm(
        CblasNoTrans,
        CblasNoTrans,
        n,
        n,
        n,
        ATLAS_ALPHA,
        B,
        n,
        A,
        n,
        ATLAS_BETA,
        C,
        n);
}

void atlas_block_mm(int n, int block_size, double *A, double *B, double *C)
{
    int num_block = n / block_size;

    for (int i = 0; i < num_block; i++)
        for (int j = 0; j < num_block; j++)
            for (int k = 0; k < num_block; k++)
                ATL_dgemm(
                    CblasNoTrans,
                    CblasNoTrans,
                    block_size,
                    block_size,
                    block_size,
                    ATLAS_ALPHA,
                    &B[(n * block_size * k) + (block_size * j)],
                    n,
                    &A[(n * block_size * i) + (block_size * k)],
                    n,
                    ATLAS_BETA,
                    &C[(n * block_size * i) + (block_size * j)],
                    n);
}