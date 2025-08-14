class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q; // node + index
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long firstIndex = q.front().second; // smallest index in this level
            long long lastIndex = firstIndex;        // will update with the last node's index

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                long long curIndex = index - firstIndex; // normalize
                lastIndex = curIndex;

                if (node->left)  q.push({node->left, curIndex * 2});
                if (node->right) q.push({node->right, curIndex * 2 + 1});
            }

            maxWidth = max(maxWidth, lastIndex + 1);
        }
        return (int)maxWidth;
    }
};
