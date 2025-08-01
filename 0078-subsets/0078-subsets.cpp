class Solution {
public:
    vector<vector<int>> result;
    void generate(vector<int>& nums, vector<int>& current, int index) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        // Exclude current element
        generate(nums, current, index + 1);

        // Include current element
        current.push_back(nums[index]);
        generate(nums, current, index + 1);
        current.pop_back();  // backtrack
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        generate(nums, current, 0);
        return result;
    }
};
