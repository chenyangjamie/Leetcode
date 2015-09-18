/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// iterative solution   12ms

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        stack<ListNode*> sta;
        ListNode* result;
        ListNode* temp;
        while(head != NULL){
            sta.push(head);
            head = head->next;
        }
        result = sta.top();
        temp = sta.top();
        sta.pop();
        while(!sta.empty()){
            temp->next = sta.top();
            sta.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return result;
    }
};


// recursive solution   8ms
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* current = head;
        ListNode* temp;
        ListNode* rest = head->next->next;
        
        current->next->next = current;
        temp = current->next;
        current->next = NULL;
        current = temp;
        
        while(rest != NULL){
            temp = rest;
            rest = rest->next;
            temp->next = current;
            current = temp;
        }
        return current;
    }
};
*/
