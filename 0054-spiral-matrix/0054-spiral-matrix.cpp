class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; // Stores the spiral order elements
    
    if (matrix.empty()) return result; // If matrix is empty, return empty result

    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    int top = 0, bottom = m - 1;   // Boundaries for rows
    int left = 0, right = n - 1;   // Boundaries for columns

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        top++; // Move top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(matrix[i][right]);
        }
        right--; // Move right boundary left

        // Check if there are rows remaining to traverse
        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--; // Move bottom boundary up
        }

        // Check if there are columns remaining to traverse
        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++; // Move left boundary right
        }
    }
    
    return result; // Return the final spiral order
}
};