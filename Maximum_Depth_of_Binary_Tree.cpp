/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Straight Forward Revursive Solution:
 
class Solution {
public:
    int maxCount = 0;
    int maxDepth(TreeNode* root) {
        int count = 0;
        dfstrav(root,count);
        return maxCount;
    }
    void dfstrav(TreeNode* root,int& count){
        if(root == NULL){
            if(count > maxCount)
                maxCount = count;
            return;
        }
        count+=1;
        dfstrav(root->left,count);
        if(root->left != NULL)
            count-=1;
        dfstrav(root->right,count);
        if(root->right != NULL)
            count-=1;
    }
};

//Shorter Solution, consider from atomic operation!!!

/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
*/
