class Solution {
public:
    int l = INT_MAX;
    int r = INT_MIN;

    void solve(TreeNode* root, map<int, map<int, vector<int>>>& mp, int level, int hight) {
        if (!root) return;

        l = min(l, level);
        r = max(r, level);

        mp[level][hight].push_back(root->val);

        solve(root->left, mp, level - 1, hight + 1);
        solve(root->right, mp, level + 1, hight + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;   // ordered map
        vector<vector<int>> ans;

        solve(root, mp, 0, 0);

        for (int i = l; i <= r; i++) {
            vector<int> col;
            for (auto &p : mp[i]) {  // iterate all heights in order
                auto nodes = p.second;
                sort(nodes.begin(), nodes.end()); // same position -> sort
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
