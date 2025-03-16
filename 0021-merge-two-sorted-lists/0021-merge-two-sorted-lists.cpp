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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* dummyHead = new ListNode(0); // Dummy node to simplify result handling
        ListNode* curr = dummyHead; // Pointer to build the result list

        while (list1 != nullptr && list2 != nullptr) { // Traverse both lists
            if (list1->val < list2->val) { // If list1's value is smaller
                curr->next = list1; // Link list1's node to the result
                list1 = list1->next; // Move list1 forward
            } else { // If list2's value is smaller or equal
                curr->next = list2; // Link list2's node to the result
                list2 = list2->next; // Move list2 forward
            }
            curr = curr->next; // Move the result pointer forward
        }

        // If one list is not empty, directly attach the remaining nodes
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }

        return dummyHead->next; // Return the merged list (excluding dummy node)
    
    }
};