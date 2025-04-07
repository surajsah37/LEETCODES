class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
    int minLen = INT_MAX;
    int sum = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        sum += nums[end];  // Expand the window by adding nums[end]

        // Shrink the window as long as sum is >= target
        while (sum >= target) {
            minLen = min(minLen, end - start + 1);  // Update minimal length
            sum -= nums[start];  // Shrink the window from the left
            start++;  // Move start forward
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}
};