/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int b0 = 0;
        int b1 = 0;
        for(int i = 0; i < nums.size(); i++){
            b0 = (b0 ^ nums[i]) & (~b1);
            b1 = (b1 ^ nums[i]) & (~b0);
        }
        return b0;
    }
};
