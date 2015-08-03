/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //if(nums.empty()) return -1;
        int i=0;
        for(i = 0;i < (nums.size()-1); i++){
            if(nums[i] > nums[i+1])
                return nums[i+1];
        }
        return nums[0];
    }
};
