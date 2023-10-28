# output as png image
set terminal png

# save file
set output outputfile

# graph title
set title plottitle

# y-axis grid
set grid y

#x-axis label
set xlabel "Matrix Size (n)"

#y-axis label
set ylabel "Time Taken (ms)"

set key left

set style line 1 \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5

#plot data from output data
plot inputfile with linespoints linestyle 1 title linetitle