class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> result(n); // Initialize result array with same size

        int posIndex = 0; // Start placing positive numbers from index 0 (even indices)
        int negIndex = 1; // Start placing negative numbers from index 1 (odd indices)

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) { // If current number is positive
                result[posIndex] = nums[i]; // Place at posIndex
                posIndex += 2; // Move to next even index
            } else { // If current number is negative
                result[negIndex] = nums[i]; // Place at negIndex
                negIndex += 2; // Move to next odd index
            }
        }

        return result; // Return the rearranged array
    }
};
