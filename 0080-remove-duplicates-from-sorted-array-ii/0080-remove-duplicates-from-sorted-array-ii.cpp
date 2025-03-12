class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if (nums.size() <= 2) return nums.size(); // If array has 2 or fewer elements, return its size

    int k = 2; // Pointer for placing elements, allowing at most 2 occurrences

    // Start from the third element and process the array
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[k - 2]) {  
            nums[k++] = nums[i];  // Place the valid element in the correct position
        }
    }

    return k; // Number of elements allowing at most twice occurrence
}
    
};