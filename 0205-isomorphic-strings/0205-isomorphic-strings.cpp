class Solution {
public:
    bool isIsomorphic(string s, string t) {
          if (s.length() != t.length()) 
        return false; // If the lengths are different, they can't be isomorphic

    vector<int> mapS(256, -1); // Array to store character mappings from string s to string t, initialized with -1
    vector<int> mapT(256, -1); // Array to store character mappings from string t to string s, initialized with -1

    for (int i = 0; i < s.length(); ++i) { // Traverse each character of both strings
        char c1 = s[i]; // Current character from string s
        char c2 = t[i]; // Current character from string t

        // If no previous mapping exists for these characters
        if (mapS[c1] == -1 && mapT[c2] == -1) {
            mapS[c1] = c2; // Map character c1 to c2
            mapT[c2] = c1; // Map character c2 to c1
        }
        // If a mapping exists but doesn't match the current characters
        else if (mapS[c1] != c2 || mapT[c2] != c1) {
            return false; // Mismatch found, strings are not isomorphic
        }
    }

    return true; // All characters matched correctly, strings are isomorphic

    }
};