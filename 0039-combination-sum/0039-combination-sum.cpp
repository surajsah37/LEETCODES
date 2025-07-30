class Solution {
public:
    // Helper function to find all combinations
    void getAllCombinations(int idx, vector<int>& candidates, int target,
                            vector<vector<int>>& ans, vector<int>& combin) 
    {
        // If target is 0, we found a valid combination
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        // If index is out of range or target becomes negative, return
        if (idx == candidates.size() || target < 0)
            return;

        // Include the current element
        combin.push_back(candidates[idx]);
        
        // Recursive call with same index (we can reuse the same element)
        getAllCombinations(idx, candidates, target - candidates[idx], ans, combin);
        
        // Backtrack: remove the last element before moving to the next index
        combin.pop_back();
        
        // Recursive call without including the current element (move to next index)
        getAllCombinations(idx + 1, candidates, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;   // To store all valid combinations
        vector<int> combin;        // Temporary vector to store current combination

        // Start the recursive process from index 0
        getAllCombinations(0, candidates, target, ans, combin);

        return ans;
    }
};
