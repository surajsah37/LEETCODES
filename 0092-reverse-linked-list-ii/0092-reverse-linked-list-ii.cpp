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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
       
    if (head == nullptr || left == right) return head; // No need to reverse if list is empty or positions are the same
        
        ListNode dummy(0); // Create a dummy node to handle edge cases
        dummy.next = head;
        ListNode* prev = &dummy; // Initialize prev to the dummy node

        // Step 1: Move prev to the node just before the left position
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist from left to right
        ListNode* current = prev->next; // The first node to be reversed
        ListNode* next = nullptr;        // Placeholder for the next node

        for (int i = 0; i < right - left; i++) {
            next = current->next;         // Store the next node
            current->next = next->next;  // Reverse the current node
            next->next = prev->next;      // Insert next node at the beginning of the reversed list
            prev->next = next;            // Move prev's next to point to the newly reversed node
        }

        // Step 3: Return the modified list
        return dummy.next; // The head of the reversed list
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
*/


        if (!head || left == right) return head; // Edge case: No reversal needed

        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;  
        ListNode* prev = dummy; // Pointer to the node before the reversal segment

        // Step 1: Move `prev` to the node before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next; // The first node in the reversal segment
        ListNode* nextNode = nullptr; // To keep track of the next node during reversal

        // Step 2: Reverse nodes from position `left` to `right`
        for (int i = 0; i < right - left; i++) {
            nextNode = curr->next; // Store the next node
            curr->next = nextNode->next; // Move `curr` forward
            nextNode->next = prev->next; // Insert `nextNode` at the beginning of the sublist
            prev->next = nextNode; // Adjust `prev` to point to the new first node
        }

        return dummy->next; // Return the updated list (excluding dummy node)
}
};