/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        int mid = (nums.size()-1)/2, end = nums.size()-1;
        vector<int> result;
        int pmid = mid, pend = end;
        bool mid_mark = true;
        //if this could be better?
        while(pend != mid || pmid != -1) {
            if(mid_mark) {
                result.push_back(nums[pmid]);
                pmid--;
                mid_mark = false;
            }
            else{
                result.push_back(nums[pend]);
                pend--;
                mid_mark = true;
            }
        }
        nums = result;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        int mid = (left+right)/2;
        int privot = nums[mid];
        int pleft = left, pright = right;
        while(pleft<=pright){
            while(nums[pleft]<privot) pleft++;
            while(nums[pright]>privot) pright--;
            if(pleft<=pright) {
                int temp = nums[pleft];
                nums[pleft] = nums[pright];
                nums[pright] = temp;
                pleft++;
                pright--;
            }
        }
        if(left<pleft-1)
            quickSort(nums,left,pleft-1);
        if(pleft<right)
            quickSort(nums,pleft,right);
    }
};
