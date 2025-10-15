class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;

        // make an array to store all values
        vector<int> arr;

        // put all node values into array
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // sort the array
        sort(arr.begin(), arr.end());

        // again fill the list with sorted values
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        // return head of sorted list
        return head;
    }
};
