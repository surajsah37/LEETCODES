class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0; // Base case: If tree is empty, return 0

        // Count the current node + nodes in left + nodes in right
        return 1 + countNodes(root->left) + countNodes(root->right);
    
    }
};