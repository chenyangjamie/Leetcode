/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string str;
        binaryTreePaths(root, result, str);
        return result;
    }
    void binaryTreePaths(TreeNode* root, vector<string>& result, string str) {
        if(root == nullptr) return;
        string s = int2string(root->val);
        str += s;
        str += "->";
        binaryTreePaths(root->left, result, str);
        binaryTreePaths(root->right, result, str);
        if(root->left == nullptr && root->right == nullptr) {
            str.pop_back();
            str.pop_back();
            result.push_back(str);
        }
    }
    string int2string (int n) {
        stringstream ss;
        string s;
        ss<<n;
        ss>>s;
        return s;
    }
};
