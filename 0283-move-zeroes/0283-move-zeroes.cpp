class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n = nums.size();     // Get array size
        int j = 0;               // Pointer for placing non-zero elements

        // First pass: move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];  // Place the non-zero element at index j
                j++;                // Move j to the next position
            }
        }

        // Second pass: fill the rest of the array with zeros
        while (j < n) {
            nums[j] = 0;
            j++;
        }
    }
};