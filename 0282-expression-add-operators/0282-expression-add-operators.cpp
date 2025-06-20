class Solution {
public:
    // Main function to add operators
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }

    // Backtracking function
    void backtrack(string& num, int target, int index,
                   string path, long long eval, long long prev,
                   vector<string>& result) {
        
        // Base case: if we reached the end of the string
        if (index == num.size()) {
            if (eval == target) {
                result.push_back(path); // If result matches target, store it
            }
            return;
        }

        // Try all possible splits
        for (int i = index; i < num.size(); i++) {
            // Skip numbers with leading zero
            if (i != index && num[index] == '0') break;

            // Current number (substring)
            string currStr = num.substr(index, i - index + 1);
            long long curr = stoll(currStr); // Convert string to number

            if (index == 0) {
                // First number: just start the path
                backtrack(num, target, i + 1, currStr, curr, curr, result);
            } else {
                // Try '+' operator
                backtrack(num, target, i + 1, path + "+" + currStr,
                          eval + curr, curr, result);

                // Try '-' operator
                backtrack(num, target, i + 1, path + "-" + currStr,
                          eval - curr, -curr, result);

                // Try '*' operator
                backtrack(num, target, i + 1, path + "*" + currStr,
                          eval - prev + (prev * curr), prev * curr, result);
            }
        }
    }
};
