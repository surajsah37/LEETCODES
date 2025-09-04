class Solution {
public:
    vector<string> result;
    void generate(int open, int close, string current, int n) {
      
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            generate(open + 1, close, current + '(', n);
        }
        if (close < open) {
            generate(open, close + 1, current + ')', n);
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(0, 0, "", n);
        return result;
    }
};
