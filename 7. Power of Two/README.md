# Leetcode

Bit Manipulation

>> << & | ~

Solution1：force and brute. 自己写的，想法是按位检索int，4字节32位，看其中有没有第二个1，有的话则false；无的话则true。

Solution2：非常巧妙的方法，用int 本身减一则若为power of 2则减一后按位取反，巧妙利用了2的乘方的二进制特性。