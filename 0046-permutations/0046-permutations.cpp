class Solution {
public:

 void backtrack(vector<int>& nums, vector<vector<int>>& result, int index) {
        // Base case: If index reaches end, store the current permutation
        if (index == nums.size()) {
            result.push_back(nums);  // Store a complete permutation
            return;
        }

        // Try placing every number at the current 'index' position
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);       // Step 1: Fix the ith element at current index
            backtrack(nums, result, index + 1); // Step 2: Recurse to fill the next index
            swap(nums[i], nums[index]);       // Step 3: Backtrack (undo the change)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;       // To store all permutations
        backtrack(nums, result, 0);       // Start from index 0
        return result;
    }
};