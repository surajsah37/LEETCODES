class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // Sorted word is used as the key
        mp[key].push_back(s);         // Group the anagrams
    }

    vector<vector<string>> result;
    for (auto& pair : mp) result.push_back(pair.second); // Extract groups

    return result;
    }
};