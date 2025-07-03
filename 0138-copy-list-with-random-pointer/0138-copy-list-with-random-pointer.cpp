/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (!head) return nullptr;

        // Step 1: Create a mapping from original node to copied node
        unordered_map<Node*, Node*> oldToNew;

        Node* curr = head;
        // First pass: create new nodes and store mapping
        while (curr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: set next and random pointers
        curr = head;
        while (curr) {
            oldToNew[curr]->next = oldToNew[curr->next];      // map next
            oldToNew[curr]->random = oldToNew[curr->random];  // map random
            curr = curr->next;
        }

        // Return the head of the copied list
        return oldToNew[head];
    }
};