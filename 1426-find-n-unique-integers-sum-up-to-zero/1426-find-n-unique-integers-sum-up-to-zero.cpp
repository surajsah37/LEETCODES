class Solution {
public:
    vector<int> sumZero(int n) {
         vector<int> result;

    // If n is odd, include 0
    if (n % 2 != 0) {
        result.push_back(0); // 0 helps make the sum zero
        n--;  // reduce n to make it even
    }

    // Add pairs of positive and negative numbers
    for (int i = 1; i <= n / 2; i++) {
        result.push_back(i);   // positive number
        result.push_back(-i);  // matching negative number
    }

    return result;
    }
};