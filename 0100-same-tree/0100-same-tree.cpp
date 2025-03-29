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
class Solution {
public:
   bool isSameTree(TreeNode* p, TreeNode* q) {
    // If both trees are empty, they are the same
    if (p == NULL && q == NULL) return true;

    // If one tree is empty but the other is not, they are different
    if (p == NULL || q == NULL) return false;

    // If the values of the current nodes are different, trees are different
    if (p->val != q->val) return false;

    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
};