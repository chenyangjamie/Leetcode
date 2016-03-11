/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space? - recursively
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* temp = head;
        stack<int> nodeStack;
        while(temp != nullptr) {
            nodeStack.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!nodeStack.empty()){
            if(nodeStack.top() != temp->val){
                return false;
            }
            temp = temp->next;
            nodeStack.pop();
        }
        return true;
    }
};
