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
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* prev = dummy; // Pointer to track the last unique node

        while (head != nullptr) {
            // If duplicate sequence found, skip all duplicate nodes
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next; // Move to the last duplicate node
                }
                prev->next = head->next; // Skip all duplicates
            } else {
                prev = prev->next; // Move prev only if no duplicate was found
            }
            head = head->next; // Move to the next node
        }

        return dummy->next; // Return modified list (excluding dummy node)
    }
};