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
    ListNode *detectCycle(ListNode *head) {
          if (head == nullptr || head->next == nullptr)
            return nullptr; // No cycle possible in empty or single-node list

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle using Floyd's cycle detection
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Cycle detected
                // Step 2: Find cycle start node
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start of cycle
            }
        }

        // No cycle detected
        return nullptr;
    }
};