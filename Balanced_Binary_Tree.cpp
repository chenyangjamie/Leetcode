/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
 /*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        if(root == nullptr) return true;
        int leftHeight = getHeight(root->left, height);
        int rightHeight = getHeight(root->right, height);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return false;
        return true;
    }
    int getHeight(TreeNode* root, int height){
        if(root == nullptr) return 0;
        int leftHeight = getHeight(root->left,height);
        int rightHeight = getHeight(root->right,height);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight+1,rightHeight+1);
    }
};
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalanced(root,height) >= 0;
    }
    int isBalanced(TreeNode* root, int height) {
        if(root == nullptr) return 0;
        int leftHeight = isBalanced(root->left,height);
        int rightHeight = isBalanced(root->right,height);
        if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight+1,rightHeight+1);
    }
};
