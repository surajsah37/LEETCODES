class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Mapping digits to letters like phone keypad
        vector<string> mapping = {
            "",     "",     "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;

        // Backtracking function
        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(current);  // Found one combination
                return;
            }

            string letters = mapping[digits[index] - '0'];
            for (char ch : letters) {
                current.push_back(ch);        // Choose
                backtrack(index + 1);         // Explore
                current.pop_back();           // Un-choose
            }
        };

        backtrack(0);
        return result;
    }
};
