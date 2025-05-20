class Solution {
public:
    int findGCD(vector<int>& nums) {
        // find the smallest number in the nums
        int smallest=*min_element(nums.begin(),nums.end());

        // find the largest number in the nums
        int largest=*max_element(nums.begin(),nums.end());
        return gcd(smallest,largest);
    }
};