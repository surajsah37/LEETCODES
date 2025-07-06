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
    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
  }
};



/*
int count=0;
        //total number of the node
        ListNode *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        };
        count/=2;
         // Step 3: Traverse again from the head to reach the middle node
        temp=head;
        while(count--)
        temp=temp->next;  // Move forward 'count' times to reach the middle node
        return temp; // Step 4: Return the pointer to the middle node

        */