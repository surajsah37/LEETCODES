class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         vector<int> count(26, 0); // To count 26 lowercase letters

        for (char ch : magazine) {
            count[ch - 'a']++;
        }

        for (char ch : ransomNote) {
            if (count[ch - 'a'] == 0) {
                return false; // Letter not available
            }
            count[ch - 'a']--; // Use the letter
        }
        return true; // All letters available
    
    }
};