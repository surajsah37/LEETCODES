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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)   return NULL;

        // invert the leftsubtree
        TreeNode*leftsubtree=invertTree(root->left);
        
        // invert the rightsubtree
        TreeNode*rightsubtree=invertTree(root->right);

        // swap the left and right chiledren
        root->left=rightsubtree;
        root->right=leftsubtree;
        return root;
    }
};