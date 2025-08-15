class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    // Step 1: Build parent map using BFS (covers all nodes)
    void buildParent(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    // Step 2: BFS to find all nodes at distance K
    void BFS(TreeNode* target, int k, vector<int>& result) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break; // Stop when we reach distance k

            dist++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // Right child
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // Parent
                if (parent[curr] && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }

        // All nodes left in queue are exactly distance k away
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        buildParent(root);    // Step 1: store parents
        BFS(target, k, result); // Step 2: find nodes
        return result;
    }
};
