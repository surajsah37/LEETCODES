class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);  // Create a new node if root is null
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);  // Go left
        } else {
            root->right = insertIntoBST(root->right, val); // Go right
        }

        return root;  // Return the updated root
    }
};
