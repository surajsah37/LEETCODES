class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int maxCount = 0;  // Stores the maximum streak of 1s found so far
    int currentCount = 0;  // Tracks the current streak of consecutive 1s

    for (int num : nums) {  // Iterate through the array
        if (num == 1) {  
            currentCount++;  // Increase count for consecutive 1s
            maxCount = max(maxCount, currentCount);  // Update maxCount if needed
        } else {
            currentCount = 0;  // Reset count when encountering 0
        }
    }
    return maxCount;  // Return the maximum consecutive 1s found
}
};