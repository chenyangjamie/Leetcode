/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
 
 /* Recursive Solution
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        trav(root,result);
        return result;
    }
    void trav(TreeNode* root, vector<int>& result){
        if(root == NULL) return;
        result.push_back(root->val);
        trav(root->left,result);
        trav(root->right,result);
        return;
    }
};
*/

 // Iterative Solution

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto n = s.top();
            s.pop();
            if(n == NULL)
                continue;
            result.push_back(n->val);
            s.push(n->right);
            s.push(n->left);
        }
        return result;
    }
};
