class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // Tracks number of unmatched '('
    int moves = 0; // Counts insertions needed
    
    for (char c : s) {
        if (c == '(') {
            open++;
        } else { // c == ')'
            if (open > 0) {
                open--; // Match with an open '('
            } else {
                moves++; // Need to insert '('
            }
        }
    }
    
    // Total moves = moves made + unmatched '(' remaining
    return moves + open;
    }
};