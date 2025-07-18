class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n = nums.size();
        int ele1 = NULL;
        int ele2 = NULL;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        int freq1 = 0, freq2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1){
                freq1++;
            }
            else if(nums[i] == ele2){
                freq2++;
            }
        }
        if(freq1 > floor(n/3))
        ans.push_back(ele1);
        if(freq2 > floor(n/3))
        ans.push_back(ele2);
        return ans;
    }
};