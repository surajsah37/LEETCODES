class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());  // Step 1: Sort the array
        long long total = 0;
        int left = 0, result = 0;
       
        for (int right = 0; right < nums.size(); right++) {
            total += (long long)nums[right];

            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left]; 
                left++;             
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};