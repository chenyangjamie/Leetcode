/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return _sortedListToBST(head, nullptr);
    }
    //when 1,3,5(odd nums) cases, hard set 1->next to nullptr, then pass the end pointer as a parameter
    TreeNode* _sortedListToBST(ListNode* head, ListNode* end) {
        if (head == end) return nullptr;
        if (head->next == end) return new TreeNode(head->val);
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != end){
            fast = fast->next;
            slow = slow->next;
            if(fast->next != end) fast = fast->next;
        }
        
        TreeNode* tNode = new TreeNode(slow->val);
        
        tNode->left = _sortedListToBST(head,slow);
        tNode->right = _sortedListToBST(slow->next,end);
        return tNode;
    }
};
