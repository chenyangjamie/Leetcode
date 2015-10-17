/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerosPointer = -1;
        for(int i=0; i<nums.size();i++){
            if(nums[i] != 0){
                if(zerosPointer != -1) {
                    swap(nums[i],nums[zerosPointer]);
                    zerosPointer++;
                }
            } else {
                zerosPointer = zerosPointer == -1 ? i : zerosPointer;
            }
        }
    }
    void swap(int& v1, int& v2) {
        v1 = v1 ^ v2;
        v2 = v1 ^ v2;
        v1 = v1 ^ v2;
    }
};
