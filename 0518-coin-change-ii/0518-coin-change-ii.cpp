class Solution {
public:
    int find(int index, int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 1; // Base case: Exact amount achieved
        if (amount < 0 || index >= n) return 0; // Base case: Invalid case

        // Check if the result is already computed
        if (dp[index][amount] != -1) return dp[index][amount];

        // Calculate and store the result in dp table
        return dp[index][amount] = find(index, n, amount - coins[index], coins, dp) 
                                   + find(index + 1, n, amount, coins, dp);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); // Initialize memoization table
        return find(0, n, amount, coins, dp);
    }
};
