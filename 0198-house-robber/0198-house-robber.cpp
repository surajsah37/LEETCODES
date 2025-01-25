/*class Solution {
public:
int find(int index,vector<int>& nums,int n,vector<int>&dp){
    if(index>=n)
    return 0;
    // already exits
    if(dp[index]!=-1)
    return dp[index];
    return dp[index]= max(nums[index]+find(index+2,nums,n,dp),find(index+1,nums,n,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,-1);
        return find(0,nums,n,dp);
    }
};

*/
// using bottom approach
class Solution {
public:
int find(int index,vector<int>& nums,int n,vector<int>&dp){
    if(index>=n)
    return 0;
    // already exits
    if(dp[index]!=-1)
    return dp[index];
    return dp[index]= max(nums[index]+find(index+2,nums,n,dp),find(index+1,nums,n,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,-1);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1;i>-1;i--)
        dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        return dp[0];
    }
};