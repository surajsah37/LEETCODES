class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        int i, j;

        // Step 1: Find the first decreasing element from the right
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {   // Identify the pivot where the order breaks
                break;
            }
        }

        // Step 2: If such an element is found, find the element just larger than it
        if (i >= 0) {
            for (j = n - 1; j > i; j--) { // Start searching from the rightmost side
                if (nums[j] > nums[i]) { // Find the next greater element
                    break;
                }
            }
            swap(nums[i], nums[j]); // Swap the two elements
        }

        // Step 3: Reverse the remaining right portion to get the next permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};