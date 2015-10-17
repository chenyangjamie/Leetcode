# Leetcode

hash table

points:

1. 分割string到vector<string>
for循环，循环之后需要再将最后一个word push_back

2. vector<string>和string的size的计算方法

3. 比较两个string的模式是否相同，可以采用
    3.1 单向映射
        hash table 遍历，一旦有hash table中项与现有项不符则为false
    3.2 双向映射 
        a. 两个hash table，互相映射
        b. 两个hash table，均衣舍到一个可比较pattern e.g. 1,2,3,4,,,