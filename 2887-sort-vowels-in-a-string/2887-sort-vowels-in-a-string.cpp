class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        
        // Store vowels in separate arrays and mark their positions
        for (char& ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                lower[ch - 'a']++;
                ch = '#';  // Mark the vowel position
            } 
            else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                upper[ch - 'A']++;
                ch = '#';  // Mark the vowel position
            }
        }

        // Collect sorted vowels
        string vowel;
        for (int i = 0; i < 26; i++) {
            while (upper[i]--) vowel += char('A' + i); // Uppercase vowels
        }
        for (int i = 0; i < 26; i++) {
            while (lower[i]--) vowel += char('a' + i); // Lowercase vowels
        }

        // Replace '#' with sorted vowels
        int index = 0;
        for (char& ch : s) {
            if (ch == '#') {
                ch = vowel[index++];
            }
        }
        
        return s;
    }
};
