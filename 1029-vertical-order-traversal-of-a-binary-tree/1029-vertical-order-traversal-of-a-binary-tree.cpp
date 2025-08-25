class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while (!q.empty()) {
            // queue से सबसे आगे का element निकालो
            auto [node, col, row] = q.front();
            q.pop();
            // उस node की value को उसके column और row में डाल दो
            nodes[col][row].insert(node->val);

            // Left child hamesha column-1, row+1 पर होगा
            if (node->left)
                q.push({node->left, col - 1, row + 1});

            // Right child hamesha column+1, row+1 पर होगा
            if (node->right)
                q.push({node->right, col + 1, row + 1});
        }

        // अब final answer तैयार करेंगे
        vector<vector<int>> ans;

        // nodes map को column-wise traverse करेंगे (left se right tak)
        for (auto &colPair : nodes) {
            vector<int> col;

            // हर column ke andar row-wise traverse (top se bottom tak)
            for (auto &rowPair : colPair.second) {
                // rowPair.second ek multiset hai (already sorted values)
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }

            // ek column complete ho gaya, answer me dal do
            ans.push_back(col);
        }

        // Final vertical traversal return karo
        return ans;
    }
};
