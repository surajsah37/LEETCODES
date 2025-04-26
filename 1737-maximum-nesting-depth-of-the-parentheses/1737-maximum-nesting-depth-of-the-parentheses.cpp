class Solution {
public:
    int maxDepth(string s) {
         int currentDepth = 0;  // Track the current depth
    int maxDepth = 0;      // Track the maximum depth

    // Loop through each character in the string
    for (char c : s) {
        if (c == '(') {  // If it's an opening parenthesis
            currentDepth++;  // Increase the depth
            maxDepth = max(maxDepth, currentDepth);  // Update max depth if needed
        } else if (c == ')') {  // If it's a closing parenthesis
            currentDepth--;  // Decrease the depth
        }
    }

    return maxDepth;  // Return the maximum depth encountered

    }
};