class Solution {
public:
    void flatten(TreeNode* root) {
         // Start from root and process until NULL
        while (root) {
            // If there is a left subtree
            if (root->left) {
                // Find the rightmost node of left subtree
                TreeNode* rightMost = root->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }

                // Attach current right subtree to rightmost node
                rightMost->right = root->right;

                // Move left subtree to right
                root->right = root->left;
                root->left = NULL;
            }

            // Move to next node (always to right)
            root = root->right;
        }
    }
};