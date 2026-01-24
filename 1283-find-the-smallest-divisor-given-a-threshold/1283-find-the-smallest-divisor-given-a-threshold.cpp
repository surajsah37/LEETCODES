class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;  // divisor must be at least 1
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = 0;

            // calculate sum of ceilings
            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= threshold) {
                right = mid; // mid is valid, try smaller
            } else {
                left = mid + 1; // mid too small, try bigger
            }
        }

        return left;
    }
};