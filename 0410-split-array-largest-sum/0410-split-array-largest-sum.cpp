class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            int count = 1;
            int currsum = 0;
            
            for (int num : nums) 
            {
                if (currsum + num > mid) 
                {
                    count++;
                    currsum = 0;
                }
                currsum += num;
            }
            if (count > k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

};