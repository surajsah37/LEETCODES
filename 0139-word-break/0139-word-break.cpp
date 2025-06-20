class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();  // Length of the input string
        unordered_set<string> dict(wordDict.begin(), wordDict.end());  // Fast lookup

        vector<bool> dp(n + 1, false);  // dp[i] = true if s[0...i-1] can be segmented
        dp[0] = true;  // Base case: empty string is always valid

        // Try every position in the string
        for (int i = 1; i <= n; i++) {
            // Try every possible break point j before i
            for (int j = 0; j < i; j++) {
                // If s[0...j-1] is valid AND s[j...i-1] is in dictionary
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;  // Mark s[0...i-1] as valid
                    break;         // No need to check more
                }
            }
        }

        return dp[n];  // Return whether full string can be segmented
    }
};
