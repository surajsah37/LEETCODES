class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;  // Initialize left and right pointers
    
    while (left < right) {  // Perform binary search
        int mid = left + (right - left) / 2;  // Compute middle index
        
        if (nums[mid] > nums[mid + 1]) 
            right = mid;  // Peak is in the left half (or at mid)
        else  
            left = mid + 1;  // Peak is in the right half
        
    }
    
    return left;  // Left will point to a peak element
    }
};