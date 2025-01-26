/*class Solution {
public:
int find(int index,int n,vector<int>& nums)
{
    if(index>=n)
    return 0;
    return max(nums[index]+find(index+2,n,nums),find(index+1,n,nums));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        return max(find(0,n-1,nums),find(1,n,nums));
    }
};
*/

// converting into the dp
class Solution {
public:
int find(int index,int n,vector<int>& nums, vector<int>&dp)
{
    if(index>=n)
    return 0;
    // if already exist
    if(dp[index]!=-1)
    return dp[index];
    return dp[index]= max(nums[index]+find(index+2,n,nums,dp),find(index+1,n,nums,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp1(n+2,-1);
        vector<int>dp2(n+2,-1);
        return max(find(0,n-1,nums,dp1),find(1,n,nums,dp2));
    }
};








