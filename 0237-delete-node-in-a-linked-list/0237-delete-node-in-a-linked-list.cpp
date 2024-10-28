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
    void deleteNode(ListNode* node) {
        ListNode* next= node->next; // Get the next node
        node->val = next->val;        // Copy the value of the next node
        node->next = next->next;      // Link to the node after the next node
        
        delete next; // Delete the next node to free memory
    
    }
};