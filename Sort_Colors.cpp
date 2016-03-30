/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left==right) return;
        if(right - left == 1) {
            if(nums[left]>nums[right]) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            return;
        }
        int mid = (left+right)/2;
        mergeSort(nums,left,mid-1);
        mergeSort(nums,mid,right);
        vector<int> new_nums;
        int pleft = left, pmid = mid;
        while(pleft <= mid-1 && pmid <= right) {
            if(nums[pleft]<=nums[pmid]) {
                new_nums.push_back(nums[pleft]);
                pleft++;
            }
            else {
                new_nums.push_back(nums[pmid]);
                pmid++;
            }
        }
        while(pleft != mid) {
            new_nums.push_back(nums[pleft]);
            pleft++;
        }
        while(pmid != right+1) {
            new_nums.push_back(nums[pmid]);
            pmid++;
        }
        for(int i=left;i<=right;i++) {
            nums[i] = new_nums[i-left];
        }
    }
};
