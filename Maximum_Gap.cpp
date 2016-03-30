/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int begin = 0, end = nums.size()-1;
        quickSort(nums,begin,end);
        int res = 0;
        for(int i=1;i<nums.size();i++){
            res = max(res,nums[i]-nums[i-1]);
        }
        return res;
    }
    void quickSort(vector<int>& nums, int begin, int end){
        int mid = (begin+end)/2;
        int pivot = nums[mid];
        int pbegin = begin, pend = end;
        while(pbegin<=pend) {
            while(nums[pbegin]<pivot) pbegin++;
            while(nums[pend]>pivot) pend--;
            if(pbegin<=pend) {
                swap(nums,pbegin,pend);
                pbegin++;
                pend--;
            }
        }
        if(begin<pbegin-1)
            quickSort(nums,begin,pbegin-1);
        if(end>pbegin)
            quickSort(nums,pbegin,end);
    }
    void swap(vector<int>& nums, int n1, int n2) {
        int temp = nums[n1];
        nums[n1] = nums[n2];
        nums[n2] = temp;
    }
};
