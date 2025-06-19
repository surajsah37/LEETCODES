class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int index, vector<int>& path) {
        result.push_back(path);  // store current subset

        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicate elements on the same level
            if (i > index && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]); // include nums[i]
            backtrack(nums, i + 1, path); // move to next
            path.pop_back(); // backtrack
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<int> path;
        backtrack(nums, 0, path);
        return result;
    }
};
