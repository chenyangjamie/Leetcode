/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool hasp = false;
        bool hasq = false;
        trav(root,p,q,hasp,hasq);
        if(hasp && hasq)
            result == root;
        return result;
    }
    void trav(TreeNode* root, TreeNode* p, TreeNode* q, bool& hasp, bool& hasq){
        if(root == NULL) return;
        bool reversep = false;
        bool reverseq = false;
        if(root == p && hasq  == true){
            result = q;
            return;
        }
        if(root == q && hasp == true){
            result = p;
            return;
        }
        if(root == p) hasp = true;
        if(root == q) hasq = true;
        if(!hasp || !hasq){
            if(hasp){ 
                hasp = false; 
                reversep = true;
            }
            if(hasq){ 
                hasq = false; 
                reverseq = true;
            }
            trav(root->left,p,q,hasp,hasq);
            if(hasp){ 
                hasp = false; 
                reversep = true;
            }
            if(hasq){ 
                hasq = false; 
                reverseq = true;
            }
            trav(root->right,p,q,hasp,hasq);
            if(reversep) hasp = true;
            if(reverseq) hasq = true;
        }
        if(hasp && hasq){
            result = root;
            hasp = false;
            hasq = false;
            return;
        }
    }
private:        
    TreeNode* result;
};
