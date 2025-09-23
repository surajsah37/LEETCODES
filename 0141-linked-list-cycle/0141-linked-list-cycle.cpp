
class Solution {
public:
    bool hasCycle(ListNode *head) {
         ListNode *slow = head;  // Slow pointer moves one step at a time
        ListNode *fast = head;  // Fast pointer moves two steps at a time

        while (fast != nullptr && fast->next != nullptr) { 
            slow = slow->next;      // Move slow pointer by one step
            fast = fast->next->next; // Move fast pointer by two steps

            if (slow == fast) { // If they meet, a cycle is detected
                return true;
            }
        }
        return false; // If we reach the end, there is no cycle
    }
};