class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, j;

        // Step 1: Find the first decreasing element from the right
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }

        // Step 2: If such an element is found, find the element just larger than it
        if (i >= 0) {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]); // Swap the two elements
        }

        // Step 3: Reverse the remaining right portion to get the next permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};