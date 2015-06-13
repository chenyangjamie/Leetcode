// Problem: https://leetcode.com/problems/invert-binary-tree/
/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/


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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) 
        return root;
        
        if(root->left != NULL && root->right != NULL){
            TreeNode *exchange_temp;
            exchange_temp = root->left;
            root->left = root->right;
            root->right = exchange_temp;
        }
        else if(root->left != NULL){
            root->right = root->left;
            root->left = NULL;
        }
        else if(root->right != NULL){
            root->left = root->right;
            root->right = NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
