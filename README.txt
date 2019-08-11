Bin Packing Project involves testing various bin packing algorithms experimentally to determine the quality of the solutions they produce. The specific bin-packing algorithms you should implement are the following five algorithms (please see the course notes for details on these algorithms):

Next Fit (NF)
First Fit (FF)
Best Fit (BF)
First Fit Decreasing (FFD)
Best Fit Decreasing (BFD)
You need to test each algorithm on lists of items of length n, as n grows, where the n items in the lists are floating point numbers between 0 and 1 generated uniformly at random. Each algorithm is defined to operate with bins of size 1. The goal of these experiments is to determine an estimate for the waste, W(A), for each of the above bin-packing algorithms, A, as a function of n, as n grows, where W(A) is defined as follows:

The waste, W(A), of a bin-packing algorithm, A, for any given list of items, is the number of bins used by the algorithm A minus the total size (i.e., the sum) of all the items in the list.
You should test multiple random sequences for each length n, and have n grow, and then plot the results on a log-log scale to see if there is a line that fits the data. If so, you should then determine the slope of that line, so as to provide experimental evidence for estimating W(A) as a function of n, and you should give that function in your report, for each algorithm, A.