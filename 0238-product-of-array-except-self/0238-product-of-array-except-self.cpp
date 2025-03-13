class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
    vector<int> answer(n, 1); // Initialize answer array with 1

    int prefix = 1; // Initialize prefix product
    for (int i = 0; i < n; i++) { 
        answer[i] = prefix; // Store the prefix product in answer[i]
        prefix *= nums[i]; // Update prefix for next element
    }

    int suffix = 1; // Initialize suffix product
    for (int i = n - 1; i >= 0; i--) { 
        answer[i] *= suffix; // Multiply current answer[i] with suffix product
        suffix *= nums[i]; // Update suffix for next iteration
    }

    return answer; // Return the final answer array
}
};