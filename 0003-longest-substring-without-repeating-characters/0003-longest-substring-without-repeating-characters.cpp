class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         vector<int> count(256, 0); // Frequency array to track character occurrence
    int first = 0, second = 0, length = 0;

    while (second < s.size()) {
        // If character at 'second' index is already present in the current window
        while (count[s[second]]) {
            count[s[first]] = 0; // Remove character at 'first' index from window
            first++; // Move first pointer forward
        }

        count[s[second]] = 1; // Mark current character as seen
        length = max(length, second - first + 1); // Update maximum length
        second++; // Move second pointer forward
    }

    return length;
}

};