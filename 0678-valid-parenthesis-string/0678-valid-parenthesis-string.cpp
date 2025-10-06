class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } 
            else if (c == ')') {
                low--;
                high--;
            } 
            else { // '*'
                low--;   // '*' as ')'
                high++;  // '*' as '('
            }

            if (high < 0) return false;  // too many ')'
            if (low < 0) low = 0;        // cannot go below zero
        }
        return low == 0;
    }
};
