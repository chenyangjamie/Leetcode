/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

/*
// This code put last k elements to the right place then deal with remaining n-k elements in the same way.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        for(;k %=n; n -= k, start += k) {
            for(int i=0; i<k; i++) { 
                swap(nums[start+i],nums[start+n-k+i]);
            }
        }
    }
};
*/

// This code reverse fisrt n-k and last k elements separtely, then reverse all array back. Bingo!
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
