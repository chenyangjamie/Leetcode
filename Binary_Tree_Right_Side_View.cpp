/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> nodesq;
        vector<int> result;
        if(root == NULL) return result;
        nodesq.push_back(root);
        while(nodesq.size()>0){
            result.push_back(nodesq[0]->val);
            vector<TreeNode*> tmp(nodesq);
            nodesq.clear();
            for(int i=0; i<tmp.size(); i++){
                TreeNode* n = tmp[i];
                if(n->right != NULL)
                    nodesq.push_back(n->right);
                if(n->left != NULL)
                    nodesq.push_back(n->left);
            }
        }
        return result;
    }
};
