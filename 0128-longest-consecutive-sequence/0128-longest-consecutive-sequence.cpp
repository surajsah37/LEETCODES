class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1, current = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;        // skip duplicates
            else if (nums[i] == nums[i - 1] + 1) current++;
            else current = 1;

            longest = max(longest, current);
        }

        return longest;
    }
};
