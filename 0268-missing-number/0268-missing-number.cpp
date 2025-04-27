class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int n = nums.size(); // Number of elements is n, so range is from 0 to n.
        int total = (n * (n + 1)) / 2;  // Sum of numbers from 0 to n
        int sum = 0;

        // Sum all elements in the array
        for (int num : nums) {
            sum += num;
        }

        // The missing number is the difference
        return total - sum;
    }
};