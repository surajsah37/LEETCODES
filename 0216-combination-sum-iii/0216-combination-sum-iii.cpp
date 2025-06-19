class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, int k, int n, vector<int>& current) {
        if (k == 0 && n == 0) {
            result.push_back(current); // valid combination
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n) break; // No point in continuing

            current.push_back(i);
            backtrack(i + 1, k - 1, n - i, current); // move to next number
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        backtrack(1, k, n, current);
        return result;
    }
};
