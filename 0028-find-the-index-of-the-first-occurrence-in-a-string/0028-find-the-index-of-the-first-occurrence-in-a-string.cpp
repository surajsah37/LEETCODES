class Solution {
public:
    int strStr(string haystack, string needle) {
       int n = haystack.size();  // Get the length of haystack
    int m = needle.size();    // Get the length of needle
    // Edge case: If needle is empty, return 0 (per problem statement)
    if (m == 0) {
        return 0;
    }
    // Edge case: If haystack is smaller than needle, return -1
    if (n < m) {
        return -1;
    }
    // Loop through the haystack to find the starting index of needle
    for (int i = 0; i <= n - m; i++) {  // Ensure we don't go out of bounds
        if (haystack[i] == needle[0]) { // Check if the first character matches
            if (haystack.substr(i, m) == needle) { // Extract substring and compare
                return i; // Return the starting index if found
            }
        }
    }
    return -1; // Return -1 if needle is not found in haystack
}

};