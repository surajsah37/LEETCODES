class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";         // Initialize the result string
        int i = 0, j = 0;           // Pointers for word1 and word2
        int m = word1.length();     // Length of word1
        int n = word2.length();     // Length of word2

        // Loop until both strings are fully traversed
        while (i < m || j < n) {
            if (i < m) result += word1[i++];  // Add from word1 if available
            if (j < n) result += word2[j++];  // Add from word2 if available
        }

        return result;  // Return the final merged string
    }
};
