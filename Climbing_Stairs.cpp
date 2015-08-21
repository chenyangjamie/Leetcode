/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int result = 0;
        int tmp = 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        result = 2;
        tmp = 1;
        for(int i = 3; i<=n; i++){
            int t = result;
            result += tmp;
            tmp = t;
        }
        return result;
    }
