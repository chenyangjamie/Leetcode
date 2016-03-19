/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* less = new ListNode(0);
        ListNode* lessCurrent = less;
        ListNode* larger = new ListNode(0);
        ListNode* largerCurrent = larger;
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            
            if(temp->val < x) {
                lessCurrent->next = temp;
                lessCurrent = lessCurrent->next;
            }
            else {
                largerCurrent->next = temp;
                largerCurrent = largerCurrent->next;
            }
        }
        lessCurrent->next = larger->next;
        return less->next;
    }
};
