class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
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
    */
 int count = 0;             // Initialize the counter
        int candidate = 0;         // Variable to store the potential majority element

        for (int i = 0; i < nums.size(); i++) {   // Traverse the entire array
            if (count == 0) {                     // If count is zero, choose new candidate
                candidate = nums[i];
            }

            if (nums[i] == candidate) {           // If current element equals candidate
                count++;                          // Increment count
            } else {
                count--;                          // Else, decrement count
            }
        }

        return candidate;                         // Return the candidate as the majority element
    }
};