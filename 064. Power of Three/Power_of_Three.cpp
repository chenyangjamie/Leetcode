/*
Given an integer, write a function to determine if it is a power of three. 

Follow up:
Could you do it without using any loop / recursion? 
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = (log10(n) / log10(3));
        return abs(x - int(x)) <= 0.00000000000001; 
    }
};
