/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        if(head->next->next == nullptr) {
            if(head->val > head->next->val) {
                head->next->next = head;
                head = head->next;
                head->next->next = nullptr;
            }
            return head;
        }
        ListNode* mid = head;
        ListNode* end = left;
        while(end != nullptr && end->next != nullptr) {
            end = end->next->next;
            mid = mid->next;
        }
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode* tempHead;
        if(left->val < right->val) {
            tempHead = left;
            left = left->next;
        }
        else {
            tempHead = right;
            right = right->next;
        }
        ListNode* temp = tempHead;
        while(left != nullptr && right != nullptr) {
            if(left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left != nullptr)
            temp->next = left;
        if(right != nullptr)
            temp->next = right;
        return tempHead;
    }
};
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        return _sortList(head);
    }
    ListNode* _sortList(ListNode* head) {
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr) {
            if(head->val > head->next->val) {
                head->next->next = head;
                head = head->next;
                head->next->next = nullptr;
            }
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = slow;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left,right);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* tempHead;
        if(left->val < right->val) {
            tempHead = left;
            left = left->next;
        }
        else {
            tempHead = right;
            right = right->next;
        }
        ListNode* temp = tempHead;
        while(left != nullptr && right != nullptr) {
            if(left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left != nullptr)
            temp->next = left;
        if(right != nullptr)
            temp->next = right;
        return tempHead;
    }
};
