class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force
        /*
        int n=nums.size(), maxsum=INT_MIN ,currentsum=0;
        for(int i=0;i<n;i++){
            if(currentsum<maxsum)
            currentsum+=maxsum;
            if(currentsum<0)
            currentsum=0;
        }
        return maxsum;
    }
    */
    int maxsum = INT_MIN;  // Stores the maximum subarray sum
    int currentsum = 0;     // Tracks the current subarray sum
    
    for (int i = 0; i < nums.size(); i++) {
        currentsum += nums[i];  // Add current element to the current sum
        maxsum = max(maxsum, currentsum); // Update maxsum if currentsum is greater
        
        if (currentsum < 0) 
            currentsum = 0; // Reset currentsum if it becomes negative
    }
    
    return maxsum;
}

};