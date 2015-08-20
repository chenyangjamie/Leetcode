/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for(int i=0; i<nums.size(); i++){
            if(mymap[nums[i]] == 1)
               mymap.erase(nums[i]); 
            else mymap[nums[i]] = 1;
        }
        vector<int> result;
        for ( auto local_it = mymap.begin(); local_it!= mymap.end(); ++local_it )
            result.push_back(local_it->first);
        return result;
    }
};
