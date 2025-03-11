class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);  // Array to store frequency of each character (size 26 for 'a' to 'z')

    // Step 1: Count frequency of each character
    for (char c : s)
   
     {
        freq[c - 'a']++;  // Convert character to index (0 for 'a', 1 for 'b', ..., 25 for 'z')
    }

    // Step 2: Find the first unique character
    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i] - 'a'] == 1) {  // Check if the character appears only once
            return i;  // Return the index of the first unique character
        }
    }

    return -1;  // No unique character found
}
    
};