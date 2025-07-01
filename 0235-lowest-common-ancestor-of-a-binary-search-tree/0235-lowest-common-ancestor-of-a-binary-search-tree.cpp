class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;  // Go left
            }
            else if (p->val > root->val && q->val > root->val) {
                root = root->right; // Go right
            }
            else {
                return root;  // Found the split point = LCA
            }
        }
        return nullptr;
    }
};
