class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fast=0;
        for(int i=0;i<nums.size();i++){
            if(i>fast)   return false;
            fast=max(fast,i+nums[i]);
        }
        return true;
    }
    
};
 