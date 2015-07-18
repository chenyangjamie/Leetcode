/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index = {0,0};
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]] = i;
        }
        for(int j=0;j<nums.size();j++){
            auto x = mymap.find(target-nums[j]);
            if(x != mymap.end()){
                if((x->second) > j){
                    index[0] = j+1;
                    index[1] = (x->second)+1;
                    return index;
                }
                else if((x->second) < j){
                    index[0] = (x->second)+1;
                    index[1] = j+1;
                    return index;
                }
            }
        }
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index = {0,0};
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > target)
            break;
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j] + nums[i] == target){
                index[0] = i+1;
                index[1] = j+1;
                return index;
                }
            }
        }
        return index;
    }
};
*/
