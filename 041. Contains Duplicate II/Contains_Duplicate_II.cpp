/*
class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i=0; i < nums.size(); i++){
            for(int j=i+1; j<min(size,k); j++){
                if(nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};
*/

class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        if(nums.size()>1){
            for(int i=0; i<nums.size(); i++){
                unordered_map<int,int>::iterator got = mymap.find(nums[i]);
                if(got != mymap.end() && (i-(got->second)) <= k)
                    return true;
                else mymap[nums[i]] = i;
            }
        }
        return false;
    }
};
