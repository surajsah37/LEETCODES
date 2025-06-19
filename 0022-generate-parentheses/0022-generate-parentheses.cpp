class Solution {
public:
    vector<string> result;

    void generate(int open, int close, string current, int n) {
        // Base case: when the current string has n pairs
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // If we can still add '(', add it
        if (open < n) {
            generate(open + 1, close, current + '(', n);
        }

        // If we can add ')', add it (only if it won't break balance)
        if (close < open) {
            generate(open, close + 1, current + ')', n);
        }
    }

    vector<string> generateParenthesis(int n) {
        generate(0, 0, "", n);
        return result;
    }
};
