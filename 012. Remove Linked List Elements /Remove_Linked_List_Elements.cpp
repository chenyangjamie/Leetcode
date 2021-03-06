/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        while(head->val == val){
            if(head->next != NULL)
                head = head->next;
            else return NULL;
        }
        ListNode* it = head;
        while(it->next != NULL){
            if(it->next->val == val)
                it->next = it->next->next;
            else it = it->next;
        }
        return head;
    }
};
