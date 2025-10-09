class Solution {
public:
    int jump(vector<int>& nums) {
       int jump=0;
       int currEnd=0; // last jump
       int fastjump=0;
       for(int i=0;i<nums.size()-1;i++){
        fastjump=max(fastjump,nums[i]+i);
        // when reached end of the jump
        if(i==currEnd){
       jump++;
       currEnd=fastjump;
        }
       }
        return jump;
    }
};



