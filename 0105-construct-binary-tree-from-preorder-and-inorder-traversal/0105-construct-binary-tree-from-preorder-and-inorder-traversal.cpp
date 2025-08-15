class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx) {
        if (start > end) return NULL;

        // Take the current root from preorder
        int rootval = preorder[idx];
        idx++;

        // Find root position in inorder
        int i = start;
        for (; i <= end; i++) {
            if (inorder[i] == rootval) break;
        }

        // Create the root node
        TreeNode* root = new TreeNode(rootval);

        // Recursively build left and right subtrees
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0; // starting index in preorder
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};
