/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int thres = nums.size()/2;
        for (int i = 0; i<nums.size(); i++){
            if(count.find(nums[i]) == count.end()){
                count[nums[i]] = 1;
            }
            else{
                count[nums[i]] += 1;
            }
            if(count[nums[i]] > thres)
                return nums[i];
        }
    }
};
