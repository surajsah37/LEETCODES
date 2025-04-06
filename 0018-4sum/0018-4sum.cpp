class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
        int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n-3; ++i) {
        for (int j = i+1; j < n-2; ++j) {
            for (int k = j+1; k < n-1; ++k) {
                for (int l = k+1; l < n; ++l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quad.begin(), quad.end());  // to avoid duplicates
                        st.insert(quad);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
    }
    */


     vector<vector<int>> res;    // To store the resulting list of quadruplets
    int n = nums.size();        // Size of the input array

    sort(nums.begin(), nums.end()); // Sort the array to use two pointers and skip duplicates

    // First loop to fix the first number of the quadruplet
    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for the first number

        // Second loop to fix the second number of the quadruplet
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for the second number

            int left = j + 1;         // Pointer for third number
            int right = n - 1;        // Pointer for fourth number

            // Two-pointer approach to find the remaining two numbers
            while (left < right) {
                // Calculate the current sum; use long long to avoid integer overflow
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    // If sum matches target, store the quadruplet
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for third number
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for fourth number
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move both pointers inward
                    left++;
                    right--;
                }
                else if (sum < target) {
                    // If current sum is less than target, move left pointer to increase sum
                    left++;
                }
                else {
                    // If current sum is greater than target, move right pointer to decrease sum
                    right--;
                }
            }
        }
    }

    return res; // Return the list of unique quadruplets
}
};