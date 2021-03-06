/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        sum -= root->val;
        if(sum == 0 && root->left == NULL && root->right == NULL) return true;
        else return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);        //advance style, tense organized
    }
};


/* Wrong Code
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        cval += root->val;                                                              //Problem: everytime call function                                                                                              //"hasPathSum", initialize cval 0;
        if(sum == cval && root->left == NULL && root->right == NULL) return true;
        else{
            bool leftchild = hasPathSum(root->left, sum);
            bool rightchild = hasPathSum(root->right, sum);
            return leftchild || rightchild;
        } 
    }
private:
    int cval = 0;
};
*/
