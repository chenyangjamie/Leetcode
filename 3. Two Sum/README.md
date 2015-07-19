# Leetcode

第一次尝试，使用了time complexity O(n^2)查找的方法，果然超时了，，，

第二次尝试，参考了discuss，学习了新的unordered_map(原理类似hash_map)，其中的find()炒鸡好用(降时间复杂度为O(n))，直接解决了运行时间问题。

unordered_map<int int> mymap;