/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        if(n < 0) return false;
        int sum = 0;
        while(n != 1){
            n = squ(n);
            if(n == 4) return false;  // 2^2 = 4; 4^2 = 16; 1^2 + 6^2 = 37; 3^2 + 7^2 = 58; 5^2 + 8^2 = 89; 8^2 + 9^2 = 145; 1^2 + 4^2 +5^2 = 42; 4^2 + 2^2 = 20; 2^2 + 0 = 4.
        }
        return true;
    }
    
    int squ(int num){
        int sum = 0;
        while(num > 0){
            int temp = num % 10;
            num = num / 10;
            sum += temp * temp;
        }
        return sum;
    }
};
