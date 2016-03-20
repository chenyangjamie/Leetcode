/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        //总结two pointer
        //this way is to find the node before or equal the mid node, another way is to set it after or equal the mid node
        //e.g. 1,2,3,4 in this case, slow = 2 but not 3
        //notice fast->next should be before fast->next->next, in case the latter one is not existed;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) { 
            fast = fast->next->next;
            slow = slow->next;
        }
        //set the end of left part to nullptr
        ListNode* right = slow->next;
        slow->next = nullptr;
        //put all nodes in right part to stack
        stack<ListNode*> stackLL;
        while(right != nullptr) {
            stackLL.push(right);
            right = right->next;
        }
        //only need ensure if stack is empty, bcs the nums of nodes in stack is less than in the rest left LL
        ListNode* current = head;
        while(!stackLL.empty()) {
            ListNode* temp = stackLL.top();
            temp->next = current->next;
            current->next = temp;
            current = temp->next;
            stackLL.pop();
        }
    }
};
