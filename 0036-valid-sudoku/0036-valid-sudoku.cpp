class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Using sets to track the numbers seen in rows, columns, and sub-boxes
    unordered_set<string> rows, cols, boxes;
    
    // Iterate over every cell in the board
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            
            // Skip empty cells
            if (num == '.') continue;
            
            // Form unique identifiers for row, column, and box
            string rowKey = "row" + to_string(i) + num;
            string colKey = "col" + to_string(j) + num;
            string boxKey = "box" + to_string(i / 3) + to_string(j / 3) + num;
            
            // Check if the number already exists in the current row, column, or box
            if (rows.count(rowKey) || cols.count(colKey) || boxes.count(boxKey)) {
                return false;  // If repetition found, the Sudoku is invalid
            }
            
            // Otherwise, mark the number as seen in the respective row, column, and box
            rows.insert(rowKey);
            cols.insert(colKey);
            boxes.insert(boxKey);
        }
    }
    
    // If no repetitions were found, the Sudoku is valid
    return true;
}
};