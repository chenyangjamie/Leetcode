# Leetcode

First Attempt:

Use recursion to find nums of sub Trees
However, excess time limited.

Second Attempt:

Optimize 1st attempt.
For example: 
      index: 1  2  3  4  5
            nums of sub trees of 2 & 4, 1 & 5 is same. Just calculate 1,2 and multiple 2.
Note 3 in 1,2,3,5 is needed to be calculated alone.
