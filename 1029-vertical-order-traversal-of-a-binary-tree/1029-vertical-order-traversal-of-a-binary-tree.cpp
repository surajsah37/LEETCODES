class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // column -> row -> multiset of nodes
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;  // node, col, row

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, col, row] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, col - 1, row + 1});
            if (node->right)
                q.push({node->right, col + 1, row + 1});
        }

        vector<vector<int>> ans;
        for (auto &colPair : nodes) {
            vector<int> col;
            for (auto &rowPair : colPair.second) {
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
