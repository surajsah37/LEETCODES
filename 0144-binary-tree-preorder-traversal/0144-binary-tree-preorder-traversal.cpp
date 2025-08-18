class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;                     
        if (!root) return result;               // If tree is empty, return empty result

        stack<TreeNode*> st;                     // Stack to simulate recursion
        st.push(root);                           // Push root node

        while (!st.empty()) {                    // Run until stack is empty
            TreeNode* node = st.top();           // Get the top node from stack
            st.pop();                            // Remove it from stack

            result.push_back(node->val);         // Step 1: Visit current node

            if (node->right) st.push(node->right); // Step 3: Push right child first
            if (node->left) st.push(node->left);   // Step 2: Push left child next
        }

        return result;                           // Return the final traversal
    }
};
