class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        // find the pivot element
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        // finding the next bigger element
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
     reverse(nums.begin()+i+1,nums.end());
    }
};