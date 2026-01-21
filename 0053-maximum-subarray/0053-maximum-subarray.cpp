class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int maxsum=nums[0];
        for(int i=0;i<nums.size();i++){
            int currsum=max(nums[i],nums[i]+currsum);
            maxsum=max(currsum,maxsum);
        }
        return maxsum;
    }
};