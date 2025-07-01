class Solution {
public:
    int index = 0;

    TreeNode* buildBST(vector<int>& preorder, int minVal, int maxVal) {
        if (index >= preorder.size()) return nullptr;

        int val = preorder[index];

        // If value is out of allowed BST bounds
        if (val < minVal || val > maxVal) return nullptr;

        // Create node and move to next index
        TreeNode* root = new TreeNode(val);
        index++;

        // Build left subtree with upper bound = current value
        root->left = buildBST(preorder, minVal, val - 1);

        // Build right subtree with lower bound = current value
        root->right = buildBST(preorder, val + 1, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MIN, INT_MAX);
    }
};
