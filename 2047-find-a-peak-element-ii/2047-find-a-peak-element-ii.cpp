class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int midCol = (left + right) / 2;

            // Find the row with the max value in midCol
            int maxRow = 0;
            for (int i = 1; i < m; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int current = mat[maxRow][midCol];
            int leftNeighbor = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

            // Check if it's a peak
            if (current > leftNeighbor && current > rightNeighbor) {
                return {maxRow, midCol};
            } else if (rightNeighbor > current) {
                left = midCol + 1;
            } else {
                right = midCol - 1;
            }
        }

        return {-1, -1}; // Just in case, though a peak always exists
    }
};
