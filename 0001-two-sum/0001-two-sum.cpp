class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;  // to store number -> index
        for(int i=0; i<nums.size(); i++) {
            int compliment = target - nums[i];
            
            // If compliment already exists in the map
            if(mp.find(compliment) != mp.end()) {
                return {mp[compliment], i};
            }
            
            // Store the current number with its index
            mp[nums[i]] = i;
        }
        return {}; // return empty if no solution
    }
};
