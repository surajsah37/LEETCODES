class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool rowZero = false, colZero = false;

    // Step 1: Check if first row has zero
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            rowZero = true;
            break;
        }
    }

    // Step 1: Check if first column has zero
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            colZero = true;
            break;
        }
    }

    // Step 2: Use first row and first column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the row
                matrix[0][j] = 0; // Mark the column
            }
        }
    }

    // Step 3: Apply zeroes based on markers (excluding first row and column)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 4: Update first row if needed
    if (rowZero) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 5: Update first column if needed
    if (colZero) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}
};
