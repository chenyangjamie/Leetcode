/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        while(temp->next != NULL){
            if(temp->val == temp->next->val){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else temp = temp->next;
        }
        return head;
    }
};
