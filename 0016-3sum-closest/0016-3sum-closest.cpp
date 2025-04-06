class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;

    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
            }
        }
    }

    return closestSum;
    }
};