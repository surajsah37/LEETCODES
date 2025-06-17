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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root == nullptr) {
            return ans; // Early return if tree is empty
        }

        queue<TreeNode*> q;  // BFS queue
        q.push(root);

        while (!q.empty()) {
            int size = q.size();         // Number of nodes in current level
            vector<int> level;           // List to store this level's values

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop();

                level.push_back(node->val); // Add node value to level

                if (node->left != nullptr) {
                    q.push(node->left);     // Add left child
                }
                if (node->right != nullptr) {
                    q.push(node->right);    // Add right child
                }
            }

            ans.push_back(level); // Add current level to answer
        }

        return ans;
    }
};
