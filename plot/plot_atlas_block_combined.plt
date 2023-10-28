# output as png image
set terminal png

# save file
set output 'images/atlas_block_combined.png'

# graph title
set title 'Blocked ijk ATLAS (different block sizes)'

# y-axis grid
set grid y

# x-axis label
set xlabel "Matrix Size (n)"

# y-axis label
set ylabel "Time Taken (ms)"

# range of y-axis
set yrange [0:22000]

set key left

set style line 1 \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5

#plot data from output data
plot 'data/benchmark_atlas_block_32.dat' with linespoints linestyle 1 lc rgb "bisque" title "32", \
     'data/benchmark_atlas_block_64.dat' with linespoints linestyle 1 lc rgb "web-blue" title "64", \
     'data/benchmark_atlas_block_128.dat' with linespoints linestyle 1 lc rgb "violet" title "128", \
     'data/benchmark_atlas_block_181.dat' with linespoints linestyle 1 lc rgb "web-green" title "181", \
     'data/benchmark_atlas_block_256.dat' with linespoints linestyle 1 lc rgb "light-red" title "256", \
     'data/benchmark_atlas_block_512.dat' with linespoints linestyle 1 lc rgb "cyan" title "512", \
     'data/benchmark_atlas_block_1024.dat' with linespoints linestyle 1 lc rgb "navy" title "1024", \
     'data/benchmark_atlas_block_1402.dat' with linespoints linestyle 1 lc rgb "dark-magenta" title "1402", \
     'data/benchmark_atlas_block_2048.dat' with linespoints linestyle 1 lc rgb "coral" title "2048", \
     'data/benchmark_atlas_block_4096.dat' with linespoints linestyle 1 lc rgb "forest-green" title "4096"