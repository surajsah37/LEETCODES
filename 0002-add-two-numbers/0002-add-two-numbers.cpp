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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* dummyHead = new ListNode(0); // Dummy node to simplify result handling
        ListNode* curr = dummyHead; // Pointer to construct the result list
        int carry = 0; // Stores carry from the previous sum

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry; // Start with the carry value
            
            if (l1) { // Add l1's value if available
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) { // Add l2's value if available
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Calculate new carry
            curr->next = new ListNode(sum % 10); // Create new node with digit
            curr = curr->next; // Move to the next node
        }

        return dummyHead->next; // Return the resultant linked list (excluding dummy node)
    }
};