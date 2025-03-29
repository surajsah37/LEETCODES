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

vector<int> preorderTraversal(TreeNode* root) {
      vector<int>result;
      if(!root)
      return result;
      stack<TreeNode*>st;
      st.push(root);
      while(!st.empty()){
         TreeNode* node = st.top();  // Get the top node
            st.pop();  // Remove the node from the stack

            result.push_back(node->val);  // Process the root node

            // Push right child first, so left is processed first (LIFO order)
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;  // Return the preorder traversal result
    }
    };



/*
   void preorderTraversalfinder(TreeNode*root,vector<int>&result){
    if(!root)
    return;
    result.push_back(root->val);
    preorderTraversalfinder(root->right,result);
    preorderTraversalfinder(root->left,result);
   }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
       preorderTraversalfinder(root,result);
       return result;
    }
};
*/