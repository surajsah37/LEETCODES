class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // Edge case: If there's only 1 row, return the original string

    vector<string> rows(min(numRows, int(s.length()))); // Store rows as strings
    int curRow = 0;  // Keep track of the current row index
    int flag = -1;    // Flag to control direction: -1 (up) or 1 (down)

    // Traverse the string and place characters in rows
    for (char c : s) {
        rows[curRow] += c;  // Add character to the current row

        // Change direction at the top or bottom row
        if (curRow == 0 || curRow == numRows - 1) {
            flag *= -1;  // Flip the flag (change direction)
        }

        curRow += flag; // Move to the next row based on flag direction
    }

    // Combine all rows into the final result
    string result;
    for (string row : rows) {
        result += row;
    }

    return result;

    }
};