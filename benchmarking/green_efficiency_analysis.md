Green Efficiency Analysis

Measurement Methodology

We used the clock() function to measure the execution time of each program. The start and end variables record the CPU time before and after the execution. The difference between these two values gives the execution time, which is then converted into seconds using CLOCKS_PER_SEC.

Each test was performed three times on the same computer, and we calculated the average execution time to compare the performance of the two implementations.

Observed Performance Differences

The first implementation uses two nested loops, making it slower. Its average execution time is 0.800743 seconds.

The second implementation uses only one loop and is much faster, with an average execution time of 0.000097 seconds.

The results show that the second implementation is approximately 8,255 times faster than the first one.

Relation Between Runtime and Energy Consumption

In general, a program that runs for a longer time uses the processor for a longer period. This leads to higher energy consumption and produces more heat.

On the other hand, a faster program generally consumes less energy.

Limitations of the Experiment

This experiment only measures the execution time of the programs. It does not directly measure the actual electrical power consumption in watts.

The results may also vary depending on the hardware used.

Practical Engineering Takeaway

Optimizing code improves performance and helps reduce energy consumption. Simpler code is also easier to read, maintain, and modify.

Reducing unnecessary calculations and removing unused code helps create more efficient programs while making better use of available resources.
