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
        ListNode*pA=headA;
        ListNode*pB=headB;
        while(pA!=pB){
            pA=pA ? pA->next:headB; // This ensures pA traverses both lists
            pB=pB ? pB->next:headA;  // This ensures pB traverses both lists
        }
        return pA;
    }
};