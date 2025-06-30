class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
        {
              return a[1]<b[1];
        });
        int count=0;
        int end=INT_MIN;
        for(auto interval:intervals){
            if(interval[0]>=end){
                // No overlap
                end=interval[1];
            }
            else{
                count++;
            }
        }
        return count;
    }
};