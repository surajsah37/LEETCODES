class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n); // allocate space for n elements

        int positIndex = 0;
        int negitIndex = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[positIndex] = nums[i];
                positIndex += 2;
            } else {
                result[negitIndex] = nums[i];
                negitIndex += 2;
            }
        }
        return result;
    }
};
