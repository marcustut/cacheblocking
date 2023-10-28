#!/bin/bash

# Exit on error
set -e

# Build the benchmarks
make benchmark

# Find and run the benchmark binaries
find bin -name 'benchmark_*' -exec ./{} ';'

# Plot the results
for FILE in data/*.dat; do
    NAME=$(basename $FILE | sed 's/.dat//g' | sed 's/benchmark_//g')
    BLOCK_SIZE=$(echo -n $NAME | tr -dc '0-9')
    BLOCK_SIZE=${BLOCK_SIZE:=0}

    gnuplot \
        -e "inputfile='$FILE'" \
        -e "outputfile='images/$NAME.png'" \
        -e "plottitle='$(echo -n $NAME | tr '_' ' ')'" \
        -e "linetitle='$BLOCK_SIZE'" \
        plot/plot_benchmark.plt
done