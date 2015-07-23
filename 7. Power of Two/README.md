# Leetcode

Bit Manipulation

>> << & | ~ ^

Solution1：force and brute. 自己写的，想法是按位检索int，4字节32位，看其中有没有第二个1，有的话则false；无的话则true。

Solution2：非常巧妙的方法，用int 本身减一则若为power of 2则减一后按位取反，巧妙利用了2的乘方的二进制特性。


各数据类型二进制长度：
int: 4byte =  32 bit 有符号signed范围：2^31-1 ~ -2^31即：2147483647 ~ -2147483648无符号unsigned范围：2^32-1 ~ 0即：4294967295 ~ 0
long: 4 byte = 32 bit 同int型
double: 8 byte = 64 bit 范围：1.79769e+308 ~ 2.22507e-308
long double: 12 byte = 96 bit 范围： 1.18973e+4932 ~ 3.3621e-4932
float: 4 byte = 32 bit 范围： 3.40282e+038 ~ 1.17549e-038
int、unsigned、long、unsigned long 、double的数量级最大都只能表示为10亿，即它们表示十进制的位数不超过10个，即可以保存所有9位整数。而short只是能表示5位；