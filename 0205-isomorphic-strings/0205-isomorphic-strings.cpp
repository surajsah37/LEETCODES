class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1; // s -> t
        unordered_map<char, char> mp2; // t -> s
        int m = s.length();
        for (int i = 0; i < m; i++) {
            char ch1 = s[i]; // Current character from string s
            char ch2 = t[i];

            if(mp1.count(ch1)){
                if(mp1[ch1]!=ch2)
                    return false;
                     }
                else{
                    mp1[ch1]=ch2;
                }
                if(mp2.count(ch2)){
                    if(mp2[ch2]!=ch1)
                        return false;
                     }
                    else{
                        mp2[ch2]=ch1;
                    }
               
           
        
        }
        return true;
    }};
