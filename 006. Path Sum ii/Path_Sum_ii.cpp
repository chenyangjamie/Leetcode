/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp_path;
        vector<vector<int>> result;
        findpaths(root,sum,temp_path,result);
        return result;
    }
private:
    void findpaths(TreeNode *root, int sum, vector<int>& temp_path, vector<vector<int>>& result){
        if(root == NULL)    
            return;
        sum -= root->val;
        temp_path.push_back(root->val);
        if(sum == 0 && root->left == NULL && root->right == NULL){
            result.push_back(temp_path);
        }
        findpaths(root->left,sum,temp_path,result);
        findpaths(root->right,sum,temp_path,result);
        temp_path.pop_back();
    }
};
