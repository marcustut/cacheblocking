#include <stdio.h>
#include <stdlib.h>

int compare_matrix(int n, double *A, double *B)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i * n + j] != B[i * n + j])
            {
                fprintf(stderr, "[FAILED] %f != %f\n", A[i * n + j], B[i * n + j]);
                return -1;
            }
    return 0;
}
