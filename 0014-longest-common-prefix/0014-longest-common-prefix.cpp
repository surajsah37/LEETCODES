class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
     // Step 2: After sorting, the common prefix will be shared between the first and last strings
        string first=v[0];
        string last=v[n-1];
        
        // Step 3: Compare characters of first and last strings until a mismatch is found
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};