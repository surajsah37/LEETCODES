class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};
        
        // Count frequency
        for (char c : s) {
            freq[c]++;
        }
        
        // Sort with custom comparator
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a] == freq[b]) 
                return a < b;        // If frequency same, sort alphabetically
            return freq[a] > freq[b]; // Otherwise, higher frequency first
        });
        
        return s;
    }
};
