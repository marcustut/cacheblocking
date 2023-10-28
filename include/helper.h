#include <stdlib.h>

double random_number(int min, int max)
{
    return rand() % max + min;
}

void init_random_square_matrix(int n, double *mat, int min, int max)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i * n + j] = random_number(min, max);
}