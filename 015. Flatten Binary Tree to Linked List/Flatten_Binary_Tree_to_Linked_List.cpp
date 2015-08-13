/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
 
//Bad Example:

/*
class Solution {
public:
    void flatten(TreeNode* root){
        TreeNode* newroot = NULL;
        TreeNode* temp = newroot;
        trav(root,temp);
        root = newroot;
    }
    void trav(TreeNode* root, TreeNode*& temp){
        if(root == NULL) return;
        if(temp == root){
            temp = root;
        }
        else{
            temp->right = root;
            temp->left = NULL;
            temp = temp->right;
        }
        trav(root->left,temp);
        trav(root->right,temp);
    }
};
*/

//Straight Forward Recursive:

/*
class Solution{
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right)
            root = root->right;
        root->right = tmp;
    }
};
*/

//Reverse thinking:

 /*
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* newroot = NULL;
        trav(root,newroot);
    }
    void trav(TreeNode* root, TreeNode*& newroot){
        if(root == NULL) return;
        trav(root->right,newroot);
        trav(root->left,newroot);
        root->right = newroot;
        root->left = NULL;
        newroot = root;
    }
};
*/
