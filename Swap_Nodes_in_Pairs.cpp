/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prior;
        while(first != nullptr && second != nullptr) {
            first->next = second->next;
            second->next = first;
            if(first != head) {
                prior->next = second;
            }
            else {
                head = second;
            }
            prior = first;
            if(first->next != nullptr) {
                second = first->next->next;
                first = first->next;
            }
            else return head;
        }
        return head;
    }
};
