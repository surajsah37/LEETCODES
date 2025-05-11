class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          int n = nums.size();
        unordered_map<int, int> mpp; // Hash map to store the number and its index
        
        for (int i = 0; i < n; i++) {
            int num = nums[i]; // Get the current number
            int moreNeeded = target - num; // Calculate the complement
            
            // If the complement is found in the map, return the indices
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i}; // Return the index of the complement and current index
            }
            
            // Store the current number with its index in the map
            mpp[num] = i;
        }
        
        return {-1, -1}; // Return {-1, -1} if no solution found
    
    }
};