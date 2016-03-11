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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr; 
        ListNode* p1 = head;
        int pos = n;
        while(p1->next != nullptr && pos > 1) {
            pos--;
            p1 = p1->next;
        }
        if(pos>1) return nullptr;
        if(p1->next == nullptr) {
            return head->next;
        }
        p1 = p1->next;
        ListNode* p2 = head;
        while(p1->next != nullptr){
            p2 = p2->next;
            p1 = p1->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};
