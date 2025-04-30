class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
















  /*
         if (s.length() != t.length()) return false;  // If lengths are different, they can't be anagrams

    vector<int> freq(26, 0);  // Array to store frequency of each character (size 26 for 'a' to 'z')

    // Step 1: Count frequency of characters in string 's'
    for (char c : s) {
        freq[c - 'a']++;  // Increment count for character in 's'
    }

    // Step 2: Subtract frequency using characters in string 't'
    for (char c : t) {
        freq[c - 'a']--;  // Decrease count for character in 't'
    }

    // Step 3: Check if all counts are zero (if yes, s and t are anagrams)
    for (int count : freq) {
        if (count != 0) return false;  // If any count is nonzero, they are not anagrams
    }

    return true;  // All counts are zero, so they are anagrams

    }
    */