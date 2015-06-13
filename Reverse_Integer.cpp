// Problem: https://leetcode.com/problems/reverse-integer/

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/


// Solution:
class Solution {
public:
    int reverse(int x) {
        long input = x;
        long reverse_num = 0;
        while(input != 0){
            reverse_num = reverse_num * 10 + input % 10;
            input = input / 10;
        }
        
        //check if reverse number is overflow or not
        //Integer.MAX_VALUE = 2147483647 
        //Integer.MIN_VAlUE = -2147483648 
        if(reverse_num > 2147483647 || reverse_num < -2147483648)
        return 0;
        
        //Tip: % will return negetive number, so the following is unnecessary
        //if(x<0) return reverse_num*-1;
        
        
        return (int)reverse_num;
    }
};
