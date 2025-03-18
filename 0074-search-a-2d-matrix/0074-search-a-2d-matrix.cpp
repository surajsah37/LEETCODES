class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();     // Number of rows
    int n = matrix[0].size();  // Number of columns
    
    int left = 0, right = m * n - 1;  // Treat the matrix as a 1D array
    
    while (left <= right) {  // Standard binary search loop
        int mid = left + (right - left) / 2;  // Calculate mid index
        int mid_value = matrix[mid / n][mid % n];  // Convert 1D index to 2D
        
        if (mid_value == target)
            return true;  // Target found
        
        if (mid_value < target)
            left = mid + 1;  // Search right half
        else
            right = mid - 1;  // Search left half
    }
    
    return false;  // Target not found
}
};