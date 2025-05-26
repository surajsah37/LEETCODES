class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> count; // To track count of 'a', 'b', 'c' in the window
    int result = 0;
    int start = 0;

    // Move end pointer through the string
    for (int end = 0; end < s.length(); ++end) {
        count[s[end]]++; // Include current character in window

        // While window has at least one of each character
        while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
            result += s.length() - end; // All substrings from start to end are valid
            count[s[start]]--; // Shrink window from left
            start++;
        }
    }

    return result; 
    }
};