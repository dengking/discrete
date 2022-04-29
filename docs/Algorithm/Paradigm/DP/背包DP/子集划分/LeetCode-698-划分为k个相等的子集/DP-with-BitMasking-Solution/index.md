https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/335668/DP-with-Bit-Masking-Solution-%3A-Best-for-Interviews

Now coming to our problem, we can represent each number and sum in binary.
We'll use dynamic programming to find whether the array can be partitioned into k subsets of equal sum. For this, we create two arrays of size = power set of array elements. why?