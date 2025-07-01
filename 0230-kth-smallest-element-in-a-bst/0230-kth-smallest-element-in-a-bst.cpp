class Solution {
public:
    int count = 0;
    int result = -1;
    void inorder(TreeNode* root, int k) {
        if (root == nullptr) return;
        inorder(root->left, k);  // Step 1: Left
        count++;                 // Step 2: Visit current node
        if (count == k) {
            result = root->val;
            return;
        }
        inorder(root->right, k); // Step 3: Right
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
