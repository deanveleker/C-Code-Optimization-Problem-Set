# C-Code-Optimization-Problem-Set

Given an array of 2n − 1 integers containing integers between 1 and n inclusive, every integer, except one,
will appear twice in the array.

Write a function that finds the integer that occurs only once. A base implementation is given to you.

See the base implementation in part2.c function oddball.

Assume the input array is always properly formatted and it follows the guidelines mentioned above. Also, assume n ≥ 2.

Show at least two ways of optimizing this algorithm and place them both in part2.c. Indicate using comments
about the optimizations you have made and why you made them. Label the best version of your algorithm
as function oddball. Keep all other versions of the oddball function in part2.c either commented
out (use #ifdefs) or label the function differently.

Your performance will be judged based on the raw speedup of your code, the runtime complexity, and memory usage.

Please understand the function oddball before jumping to optimize it.

With the Makefile and part2-main.c provided, doing make N=100, to compile the code will cause the value
of n to be set to 100.

You must run make in order to create the executables that you can then run. For example:

make N=30000
./part2_def
./part2_o1
./part2_o2
./part2_rng
make clean
make N=40000
