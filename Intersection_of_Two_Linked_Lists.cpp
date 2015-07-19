/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curp1 = headA;
        ListNode *curp2 = headB;
        
        while(curp1 != nullptr && curp2 != nullptr){
            curp1 = curp1->next;
            curp2 = curp2->next;
        }
        
        if(curp1 != nullptr){
            curp2 = headA;
            while(curp1 != nullptr){
                curp1 = curp1->next;
                curp2 = curp2->next;
            }
            curp1 = headB;
        }
        else if(curp2 != nullptr){
            curp1 = headB;
            while(curp2 != nullptr){
                curp2 = curp2->next;
                curp1 = curp1->next;
            }
            curp2 = headA;
        }
        else{
            curp1 = headA;
            curp2 = headB;
        }
        
        while(curp1 != curp2){
                curp1 = curp1->next;
                curp2 = curp2->next;
            }
        
        return curp1;
    }
};
