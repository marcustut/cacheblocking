# Cache blocking for matrix multiplication

The main source code can be found in `include/` directory where there are four header files:

- `atlas.h`: Matrix multiplication using ATLAS library
- `blas.h`: Matrix multiplication using BLAS library
- `manual.h`: Matrix multiplication written manually
- `helper.h`: Helper functions for generating matrices with random numbers

> Note that the implementation was also included in the header files.

## Test

The tests can be ran by executing the `run_test.sh` script in the root directory. The script will compile the source code and run the tests. The results should be as follows if the tests are successful.

```bash
$ ./run_test.sh
[PASSED] test_atlas_mm.c
[PASSED] test_blas_mm.c
[PASSED] test_blas_block_mm.c
[PASSED] test_manual_block_mm.c
[PASSED] test_atlas_block_mm.c
```

The source code for the tests can be found in the `test/` directory.

## Benchmark

The benchmark can be ran by executing the `run_benchmark.sh` script in the root directory. The script will compile the source code and run the benchmark. 

```bash
$ ./run_benchmark.sh
```

The results will be stored as `.dat` files in the `data/` directory and the script will then invoke `gnuplot` to plot the results. The plots will be stored in the `images/` directory and the plotfiles resides in the `plot/` directory. The source code for the benchmark can be found in the `benchmark/` directory.

## Refrences

- [Adding Nested Loops Makes this Algorithm 120x FASTER?](https://www.youtube.com/watch?v=QGYvbsHDPxo&)
- [What Every Programmer Should Know About Memory](https://people.freebsd.org/~lstewart/articles/cpumemory.pdf)