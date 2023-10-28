void manual_block_mm(int n, int block_size, double *A, double *B, double *C)
{
    int num_block = n / block_size;

    for (int bi = 0; bi < num_block; bi++)
        for (int bj = 0; bj < num_block; bj++)
            for (int bk = 0; bk < num_block; bk++)
                for (int i = 0; i < block_size; i++)
                    for (int j = 0; j < block_size; j++)
                    {
                        int c_idx = bi * block_size * num_block * block_size + i * num_block * block_size +
                                    bj * block_size + j;
                        double sum = 0;
                        for (int k = 0; k < block_size; k++)
                        {
                            int a_idx = bi * block_size * num_block * block_size + i * num_block * block_size +
                                        bk * block_size + k;
                            int b_idx = bk * block_size * num_block * block_size + k * num_block * block_size +
                                        bj * block_size + j;
                            sum += A[a_idx] * B[b_idx];
                        }
                        C[c_idx] += sum;
                    }
}

void manual_mm(int n, double *A, double *B, double *C)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}