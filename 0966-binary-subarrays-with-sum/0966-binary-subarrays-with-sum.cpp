class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount; // Map to store prefix sums and their frequencies
    prefixCount[0] = 1; // Base case: prefix sum 0 occurs once

    int sum = 0;    // Current prefix sum
    int count = 0;  // Total valid subarrays

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i]; // Update the prefix sum

        // Check if (sum - goal) has occurred before
        if (prefixCount.find(sum - goal) != prefixCount.end()) {
            count += prefixCount[sum - goal]; // Add its count to the result
        }

        // Update the frequency of the current prefix sum
        prefixCount[sum]++;
    }

    return count; // Return total subarrays found
}
};