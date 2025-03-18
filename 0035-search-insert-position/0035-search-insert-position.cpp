class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
       int left = 0, right = arr.size() - 1;  // Initialize left and right pointers
    
    while (left <= right) {  // Binary search loop
        int mid = left + (right - left) / 2;  // Calculate middle index
        
        if (arr[mid] == target)  
            return mid;  // Target found, return its index
        
        if (arr[mid] < target)  
            left = mid + 1;  // Search in the right half
        else  
            right = mid - 1;  // Search in the left half
    }
    
    return left;  // Left points to the insert position
    }
};