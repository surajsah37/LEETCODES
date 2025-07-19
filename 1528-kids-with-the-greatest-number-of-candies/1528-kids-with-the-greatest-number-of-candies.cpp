class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();  // Get the number of kids

        // Find the current maximum number of candies any kid has
        int maxC = *max_element(begin(candies), end(candies));

        vector<bool> result(n, false);  // Initialize result array with 'false' of size n

        // Loop through each kid
        for (int i = 0; i < n; i++) {
            // If after giving extraCandies the current kid has at least as many as max
            if (candies[i] + extraCandies >= maxC) {
                result[i] = true;  // Mark true in result
            }
        }

        return result;  // Return the result array
    }
};
