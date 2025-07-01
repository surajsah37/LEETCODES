class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect swapped nodes
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;     // first wrong node
            }
            second = root;        // second wrong node
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap values of the two nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
