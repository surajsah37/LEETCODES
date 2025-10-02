class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
     {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child=0;
        int cookies=0;
        // Try to satisfy each child with a cookie
        while(child<g.size() && cookies<s.size())
        {
        if(s[cookies]>=g[child])  // If cookie is big enough, satisfy child
        {
        child++;
        }
        cookies++;
        }
        return child;
        }
   
};