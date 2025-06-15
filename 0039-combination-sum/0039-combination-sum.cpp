class Solution {
public:
    // Helper function to get all combinations
    void getAllCombinations(int idx, vector<int>& candidates, int target,
                            vector<vector<int>>& ans, vector<int>& combin) {

        // If target becomes zero, store the current combination
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        // If index goes out of bounds or target is negative, return
        if (idx == candidates.size() || target < 0)
            return;

        // Include current candidate (multiple times allowed)
        combin.push_back(candidates[idx]);
        // Call with same index because multiple uses allowed
        getAllCombinations(idx, candidates, target - candidates[idx], ans, combin);
        combin.pop_back(); // Backtrack

        // Exclude current candidate and move to next index
        getAllCombinations(idx + 1, candidates, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(0, candidates, target, ans, combin);
        return ans;
    }
};
