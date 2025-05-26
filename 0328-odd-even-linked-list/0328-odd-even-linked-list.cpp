class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Base cases: empty or single-node list
        if (head == nullptr || head->next == nullptr)
            return head;

        // Initialize odd and even pointers
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save starting point of even list

        // Reorder nodes
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;   // Link odd to next odd
            odd = odd->next;          // Move odd pointer

            even->next = odd->next;   // Link even to next even
            even = even->next;        // Move even pointer
        }

        // Connect the end of odd list to the head of even list
        odd->next = evenHead;

        return head; // Return the rearranged list
    }
};
