class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, candidate = 0;

        // Step 1: Find the candidate
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                freq++;
            } else {
                freq--;
            }
        }
        // Step 2: Verify the candidate
        int count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }
        if (count > nums.size() / 2) {
            return candidate;
        }
        // If no majority element exists (depends on problem constraints)
        return -1;  // Or throw an error if majority is guaranteed
    }
};
