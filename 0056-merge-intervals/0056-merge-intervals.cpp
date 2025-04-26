class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end()); // Sort by starting time
    vector<vector<int>> ans;
    
    for (auto interval : intervals) {
        // If ans is empty OR no overlap, add new interval
        if (ans.empty() || ans.back()[1] < interval[0]) {
            ans.push_back(interval);
        } else {
            // Overlap: merge by updating the end time
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }
    
    return ans;
    }
};