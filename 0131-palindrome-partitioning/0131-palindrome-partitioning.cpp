class Solution {
public:
    // Correct spelling of the helper function
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void backtrack(int start, string &s, vector<string> &path, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(path); // Found a valid partition
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1)); // Choose
                backtrack(end + 1, s, path, result);              // Explore
                path.pop_back();                                  // Un-choose (Backtrack)
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }
};
