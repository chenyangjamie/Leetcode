/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //straightforward code
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* comp;
        while(head->val == head->next->val){
            comp = head;
            while(comp->next != nullptr && comp->val == comp->next->val) {
                comp = comp->next;
            }
            head = comp->next;
            if(head == nullptr || head->next == nullptr) return head;
        }
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head->next;
        ListNode* tbefore = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->val == temp->next->val) {
                comp = temp;
                while(comp->next != nullptr && comp->val == comp->next->val) {
                    comp = comp->next;
                }
                tbefore->next = comp->next;
                temp = tbefore->next;
            }
            else {
                temp = temp->next;
                tbefore = tbefore->next;
            }
        }
        return head;
    }
};
