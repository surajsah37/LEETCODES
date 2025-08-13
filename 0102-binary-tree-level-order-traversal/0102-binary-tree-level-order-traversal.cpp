class Solution {
public:
   vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;     // Final answer: each vector<int> stores one level

    if (!root)                      // If tree is empty, return empty result
        return result;

    queue<TreeNode*> q;              // Queue to store nodes for BFS
    q.push(root);                    // Start with root node in the queue

    while (!q.empty()) {             // Repeat until queue is empty (no more nodes)
        int size = q.size();         // Number of nodes in current level
        vector<int> level;           // Vector to store values of current level

        for (int i = 0; i < size; i++) {   // Process all nodes of current level
            TreeNode* node = q.front();    // Get the first node from the queue
            q.pop();                       // Remove it from the queue

            level.push_back(node->val);    // Add its value to current level list

            if (node->left)                // If left child exists
                q.push(node->left);        // Add left child to queue
            if (node->right)               // If right child exists
                q.push(node->right);       // Add right child to queue
        }

        result.push_back(level);           // Add current level's values to result
    }

    return result;                         // Return the final level order result
}
};