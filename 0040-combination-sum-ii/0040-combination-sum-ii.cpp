class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, vector<int>& path, int index) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicate elements at same level
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // If number is greater than target, no need to continue
            if (candidates[i] > target) break;

            path.push_back(candidates[i]); // choose
            backtrack(candidates, target - candidates[i], path, i + 1); // move to next
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        vector<int> path;
        backtrack(candidates, target, path, 0);
        return result;
    }
};
