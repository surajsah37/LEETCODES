class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element( nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<right){
            int mid=left+(right-left)/2;
            // split the maxsum
            int count=1;
            int currentsum=0;
            for(int num:nums){
                if(currentsum+num>mid){
                    count++;
                    currentsum=num;
                }
                else{
                    currentsum+=num;
                }
            }
            // if we split into two or more part
            if(count<=k){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};