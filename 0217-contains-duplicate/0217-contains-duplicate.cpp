class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j])
                return true;
            }
        }
        return false;
    }
    */
unordered_map<int, int> freqMap;
    
    for (int num : nums) {
        if (freqMap[num]++)  // If num already exists in map, return true
            return true;
    }
    
    return false;  // No duplicates found
}
};