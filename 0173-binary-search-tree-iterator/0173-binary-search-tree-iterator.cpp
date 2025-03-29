/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    private:
    stack<TreeNode*> st; // Stack to simulate recursion

    // Helper function to push all left nodes into the stack
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
public:
        // Constructor: Initialize iterator and push leftmost nodes
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    // Returns the next smallest element
    int next() {
        TreeNode* node = st.top(); // Get the top element
        st.pop(); // Remove it from stack
        if (node->right) { // Push leftmost nodes of the right subtree
            pushLeft(node->right);
        }
        return node->val;
    }

    // Returns true if there are more elements in in-order traversal
    bool hasNext() {
        return !st.empty();
    }
};
    
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */