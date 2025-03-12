class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.empty()) return 0; // Edge case: if the array is empty, return 0

    int k = 1; // Pointer to place the next unique element

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {  
            nums[k++] = nums[i];  // Place the unique element at the correct position
        }
    }

    return k; // Number of unique elements
}

};