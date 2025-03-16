/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head; // Edge cases: empty list, single node, no rotation
        
        ListNode* temp = head;
        int length = 1; // Initialize length as 1 since we start from head

        // Step 1: Compute the length of the list
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        // Step 2: Make the list circular
        temp->next = head; // Connect last node to head to form a cycle

        // Step 3: Compute the new head position
        k = k % length; // Handle cases where k >= length
        int stepsToNewHead = length - k;

        // Step 4: Find the new tail (node just before new head)
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }

        // Step 5: Break the cycle and set new head
        head = temp->next; // New head after rotation
        temp->next = NULL; // Break the cycle

        return head;
    
    }
};