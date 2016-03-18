/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* result = new ListNode(0);
        ListNode* resultPass = result;
        int add = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int temp;
            temp = (l1!=nullptr ? l1->val : 0) + (l2!=nullptr ? l2->val : 0) + add;
            add = temp / 10;
            temp = temp % 10;
            ListNode* newNode = new ListNode(temp);
            resultPass->next = newNode;
            resultPass = resultPass->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(add > 0) {
            ListNode* newNode = new ListNode(add);
            resultPass->next = newNode;
        }
        return result->next;
    }
};
