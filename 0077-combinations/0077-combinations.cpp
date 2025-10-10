class Solution {
public:
     vector<vector<int>> ans;      // To store all combinations
    vector<int> current;          // To store current combination

    void backtrack(int start, int n, int k) {
        // Base case: if combination size == k, add to result
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Choose each number starting from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            current.push_back(i);         // choose i
            backtrack(i + 1, n, k);       // explore further
            current.pop_back();           // undo choice (backtrack)
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);   // start recursion from 1
        return ans;
    }
};