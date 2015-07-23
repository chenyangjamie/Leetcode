//Given an integer, write a function to determine if it is a power of two.

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int temp = 0;
        bool mark = 0;
        if(n <= 0) return false;
        for(int i = 0; i < 32; i++){
            temp = n & 1;
            if(temp == 1 && mark == 1)
                return false;
            if(temp == 1 && mark == 0)
                mark = 1;
            n = n >> 1;
        }
        return true;
    }
};
*/

class Solution{
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        n &= n-1;
        return n == 0;
    }
};
