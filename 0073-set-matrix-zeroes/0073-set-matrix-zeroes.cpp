class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    unordered_set<int> zeroRows; // Store indices of rows that need to be zeroed
    unordered_set<int> zeroCols; // Store indices of columns that need to be zeroed

    // Step 1: Identify rows and columns that contain zeroes
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows.insert(i); // Mark the row index
                zeroCols.insert(j); // Mark the column index
            }
        }
    }

    // Step 2: Set entire rows to zero
    for (int row : zeroRows)
     
     {  
        // Iterate through all marked row indices
        for (int j = 0; j < n; ++j) {
            matrix[row][j] = 0; // Zero out the entire row
        }
    }

    // Step 3: Set entire columns to zero
    for (int col : zeroCols) { // Iterate through all marked column indices
        for (int i = 0; i < m; ++i) {
            matrix[i][col] = 0; // Zero out the entire column
        }
    }
}
};