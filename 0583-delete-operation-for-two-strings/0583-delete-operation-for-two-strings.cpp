class Solution {
public:
    int m, n;

    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        if (i >= m && j >= n) return 0;

        if (i >= m) return n - j;  // delete remaining chars of word2
        if (j >= n) return m - i;  // delete remaining chars of word1

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        } else {
            int delete_word1_i = 1 + solve(i + 1, j, word1, word2, dp);
            int delete_word2_j = 1 + solve(i, j + 1, word1, word2, dp);
            dp[i][j] = min(delete_word1_i, delete_word2_j);
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // fix: proper initialization
        return solve(0, 0, word1, word2, dp);           // fix: pass dp
    }
};
