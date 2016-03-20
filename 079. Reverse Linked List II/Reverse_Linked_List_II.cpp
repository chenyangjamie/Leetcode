/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || head->next == nullptr) return head;
        
        //create fakeHead as former node before real head, deal with the reverse list includes the head node.
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        
        //find the head node of rest nodes, and set the next pointer of former node of this head node as nullptr
        ListNode* restHead = head;
        for(int i=1; i<n; i++) {
            restHead = restHead->next;
        }
        ListNode* current = restHead;
        restHead = restHead->next;
        current->next = nullptr;
        
        //find the head node of reverse part
        ListNode* revHead = head;
        for(int i=1; i<m; i++) {
            revHead = revHead->next;
        }
        
        //reverse the nodes recursively
        _reverseLL(revHead);
        
        //from the fakeHead, connect all three parts
        current = fakeHead;
        for(int i=0; i<m-1; i++) {
            current = current->next;
        }
        current->next = revHead;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = restHead;
        return fakeHead->next;
    }
    //recursively part, notice the last line: rest pointer reference is always points to the last node(the head node of reverse part)
    void _reverseLL(ListNode*& current) {
        if(current == nullptr) return;
        ListNode* rest = current->next;
        if(rest == nullptr) return;
        _reverseLL(rest);
        current->next->next = current;
        current->next = nullptr;
        current = rest;
    }
};
