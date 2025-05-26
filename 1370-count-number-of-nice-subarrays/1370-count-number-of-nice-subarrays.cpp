class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int, int> prefixCount; // Maps odd_count to how many times it occurred
    prefixCount[0] = 1; // Base case: 0 odd numbers before start

    int odd = 0;    // Current odd count
    int result = 0; // Total nice subarrays

    for (int i = 0; i < nums.size(); ++i) {
        // If the current number is odd, increase odd count
        if (nums[i] % 2 == 1) {
            odd++;
        }

        // If (odd - k) has occurred before, we can form a valid subarray
        if (prefixCount.find(odd - k) != prefixCount.end()) {
            result += prefixCount[odd - k];
        }

        // Record the current odd count
        prefixCount[odd]++;
    }

    return result;
}
};