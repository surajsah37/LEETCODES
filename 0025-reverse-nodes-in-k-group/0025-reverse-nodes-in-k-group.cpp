class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; // Edge case: No reversal needed

        ListNode* temp = head;
        int count = 0;
        
        // Step 1: Count k nodes
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        
        // If we have at least k nodes, reverse them
        if (count == k) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* nextNode = nullptr;
            
            // Step 2: Reverse k nodes iteratively
            for (int i = 0; i < k; i++) {
                nextNode = curr->next; // Store the next node
                curr->next = prev; // Reverse the link
                prev = curr; // Move prev forward
                curr = nextNode; // Move curr forward
            }
            
            // Step 3: Recursively reverse the remaining list
            head->next = reverseKGroup(curr, k);

            // Step 4: Return new head after reversal
            return prev;
        }
    
        return head; // If fewer than k nodes remain, return as is

    }
};