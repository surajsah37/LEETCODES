class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0;
        int zeroCount=0;
        int maxLen=0;
        while (right < nums.size()) {
        if (nums[right] == 0)      // If current element is 0
            zeroCount++;           // Increment the count of zeros in the window

        // If number of zeros exceeds k, shrink the window from the left
        while (zeroCount > k) {
            if (nums[left] == 0)   // If the element being removed is 0
                zeroCount--;       // Decrease the zero count
            left++;                // Move the left pointer to shrink the window
        }

        // Update the maximum length of valid window
        maxLen = max(maxLen, right - left + 1);

        right++;                   // Expand the window by moving right pointer
    }

    return maxLen;                 // Return the length of the longest valid window
    }
};