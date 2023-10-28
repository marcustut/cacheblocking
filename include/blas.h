#include <cblas.h>

#define BLAS_ALPHA 1.0
#define BLAS_BETA 1.0

void blas_block_mm(int n, int block_size, double *A, double *B, double *C)
{
    int num_block = n / block_size;

    for (int i = 0; i < num_block; i++)
        for (int j = 0; j < num_block; j++)
            for (int k = 0; k < num_block; k++)
                cblas_dgemm(
                    CblasRowMajor,
                    CblasNoTrans,
                    CblasNoTrans,
                    block_size,
                    block_size,
                    block_size,
                    BLAS_ALPHA,
                    &A[(n * block_size * i) + (block_size * k)],
                    n,
                    &B[(n * block_size * k) + (block_size * j)],
                    n,
                    BLAS_BETA,
                    &C[(n * block_size * i) + (block_size * j)],
                    n);
}

void blas_mm(int n, double *A, double *B, double *C)
{
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, BLAS_ALPHA, A, n, B, n, BLAS_BETA, C, n);
}