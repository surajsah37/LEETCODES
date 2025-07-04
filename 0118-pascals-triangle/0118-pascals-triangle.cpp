class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);  // Start with all 1s

        // Fill the inner elements
        for (int j = 1; j < i; ++j) {
            // Each element = sum of the two elements above it
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);  // Add the current row to the triangle
    }

    return triangle;
    }
};