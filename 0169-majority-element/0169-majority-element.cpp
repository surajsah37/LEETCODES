class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int count = 0;      // Count of the current candidate
    int candidate = 0;  // Variable to store the majority candidate

    // First pass: Find the majority candidate
    for (int num : nums) {
        if (count == 0) {  // If count is zero, assign new candidate
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1; // Increase or decrease count
    }

    return candidate; // The majority element is guaranteed to exist

    }
};