/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int num = 0;
        trav(root,num);
        return sum;
    }
    void trav(TreeNode* root,int num){
        if(root == NULL){//最纠结的部分，注意题设是“root-to-leaf path”
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            num = num*10 + root->val;
            sum = sum + num;
            return;
        }
        num = num*10 + root->val;
        trav(root->left,num);
        trav(root->right,num);
        return;
    }
};
*/

class Solution{
public:
    int sumNumbers(TreeNode* root, int sum = 0){
        if(root == NULL)
            return 0;
        if(root->left != NULL || root->right != NULL){
            return sumNumbers(root->left,10*sum + root->val) + sumNumbers(root->right,10*sum + root->val);
        }
        else return 10*sum + root->val;
    }
};
