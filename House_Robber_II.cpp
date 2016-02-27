/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        return max(robHelper(nums,0,n-2),robHelper(nums,1,n-1));
    }
    int robHelper(vector<int>& nums,int start, int end) {
        int first=0, second=0, total=0;
        int len = nums.size();
        for(int i=start;i<=end;i++){
            total = max(first+nums[i],second);
            first = second;
            second = total;
        }
        return total;
    }
};
