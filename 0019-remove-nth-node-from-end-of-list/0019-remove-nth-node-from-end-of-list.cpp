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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        int count=0;
        ListNode*temp=head;
        // count total number of ther list node
        while(temp){
            count++;
            temp=temp->next;
        };
        count-=n;
        if(count==0){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode*curr=head,*prev=NULL;
        while(count--){
            prev=curr;
            curr=curr->next;
        };
         prev->next=curr->next;
            delete curr;
            return head;
        }
        */

         ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Step 1: Move `first` pointer `n+1` steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Step 2: Move both `first` and `second` until `first` reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Step 3: Remove the nth node from the end
        ListNode* toDelete = second->next; // Node to remove
        second->next = second->next->next; // Skip the node

        delete toDelete; // Free memory

        return dummy->next; // Return updated list (excluding dummy node)
    }

};