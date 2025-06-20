class Solution {
public:
    // Main function that starts solving the board
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Start backtracking
    }

    // Function to check if it's valid to place 'digit' at board[row][col]
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == digit) return false;
            // Check column
            if (board[i][col] == digit) return false;
            // Check 3x3 subgrid
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == digit) return false;
        }
        return true; // All checks passed
    }

    // Recursive function to solve the board using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // If cell is empty
                if (board[row][col] == '.') {
                    // Try digits 1 to 9
                    for (char digit = '1'; digit <= '9'; digit++) {
                        // If placing digit is valid
                        if (isValid(board, row, col, digit)) {
                            board[row][col] = digit; // Place digit

                            // Recurse: if board is solved, return true
                            if (solve(board)) return true;

                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid digit found → backtrack
                }
            }
        }
        return true; // All cells filled correctly
    }
};
