# Land-Problem-CPP
Wrote code for console application that finds maximum profit for land division using dynamic programming.
Console application asks for dimensions of land which must be multiples of 5.
Computes the total land area (which must be multiple of 10) and then asks for prices of each division of 100 sq. units of land.
For example if we have 400 sq. units land, it would ask for prices of land with size 100, 200, 300 and so on until 500.
It then computes the division of this total land in a way that gives the maximum profit if sold.
There are three codes here in which top down 1 uses recursive solution with complexity O(2^n).
To reduce this complexity, top down 2 is written with an unordered map which reduces complexity to O(n^2) (Dynamic top down approach).
Then in bottom up 1, this recursive solution is transformed into iterative approach (bottom up) with unordered map and complexity O(n^2). However it is an iterative solution this time.
These are three solutions provided for the same problem in a console environment.
