class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) return result;

        int w = words[0].size();     // size of each word
        int n = words.size();        // number of words
        int total = w * n;           // total window size

        if(s.size() < total) return result;

        // Frequency map of words
        unordered_map<string, int> wordCount;
        for(auto &word : words) {
            wordCount[word]++;
        }

        // Check for each possible starting point inside the word length cycle
        for(int i = 0; i < w; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;

            // Slide the window by word size
            for(int j = i; j + w <= s.size(); j += w) {
                string word = s.substr(j, w);

                if(wordCount.count(word)) {
                    seen[word]++;
                    count++;

                    // If too many of one word, shrink from left
                    while(seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, w);
                        seen[leftWord]--;
                        left += w;
                        count--;
                    }

                    // If all words matched
                    if(count == n) {
                        result.push_back(left);
                        // Move left to look for next
                        seen[s.substr(left, w)]--;
                        left += w;
                        count--;
                    }

                } else {
                    // Reset window if invalid word found
                    seen.clear();
                    count = 0;
                    left = j + w;
                }
            }
        }

        return result;
    }
};
