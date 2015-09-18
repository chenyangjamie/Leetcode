/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* result;
        ListNode* temp;
        if(l1->val <= l2->val){
            result = l1;
            temp = l1;
            l1 = l1->next;
        }
        else {
            result = l2;
            temp = l2;
            l2 = l2->next;
        }
        
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
                continue;
            }
            if(l2 == NULL){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
                continue;
            }
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        return result;
    }
};
