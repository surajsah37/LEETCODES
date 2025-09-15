class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.empty()!=t.empty())
        return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};