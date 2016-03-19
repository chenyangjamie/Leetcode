/*
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* sortedHead = head;
        ListNode* sortedTail = head;
        head = head->next;
        sortedTail->next = nullptr;
        
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            // edge case:[1,1] solution: continue
            if(temp->val <= sortedHead->val) {
                temp->next = sortedHead;
                sortedHead = temp;
                continue;
            }
            if(temp->val >= sortedTail->val) {
                sortedTail->next = temp;
                sortedTail = sortedTail->next;
                continue;
            }
            else {
                ListNode* sortedCurrent = sortedHead;
                while(sortedCurrent != sortedTail && temp->val > sortedCurrent->next->val){
                        sortedCurrent = sortedCurrent->next;
                    }
                    temp->next = sortedCurrent->next;
                    sortedCurrent->next = temp;
                }
            }
        return sortedHead;
    }
};
