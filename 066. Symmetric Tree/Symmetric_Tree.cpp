/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
 
 //recursive
 /*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return symmetric(root->left,root->right);
    }
    bool symmetric(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr || left->val != right->val) return false;
        return symmetric(left->left,right->right) && symmetric(left->right,right->left);
    }
};
*/

//iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> left_queue;
        queue<TreeNode*> right_queue;
        if(root == nullptr) return true;
        left_queue.push(root->left);
        right_queue.push(root->right);
        while(!right_queue.empty() && !left_queue.empty()){
            TreeNode* right_node = right_queue.front();
            TreeNode* left_node = left_queue.front();
            right_queue.pop();
            left_queue.pop();
            if(right_node == nullptr && left_node == nullptr)
                continue;
            if(right_node == nullptr || left_node == nullptr)
                return false;
            if(right_node->val != left_node->val)
                return false;
            right_queue.push(right_node->right);
            right_queue.push(right_node->left);
            left_queue.push(left_node->left);
            left_queue.push(left_node->right);
        }
        return true;
    }
};
