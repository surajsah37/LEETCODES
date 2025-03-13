class Solution {
public:

    bool isPalindrome(string s) {
//        int left = 0, right = s.length() - 1;  // Two pointers at start and end

//     while (left < right) {
//         // Move left pointer forward if it's not an alphanumeric character
//         while (left < right && !isalnum(s[left])) {
//             left++;
//         }
        
//         // Move right pointer backward if it's not an alphanumeric character
//         while (left < right && !isalnum(s[right])) {
//             right--;
//         }

//         // Convert both characters to lowercase and compare
//         if (tolower(s[left]) != tolower(s[right])) {
//             return false;  // If mismatch, it's not a palindrome
//         }

//         left++;   // Move left pointer forward
//         right--;  // Move right pointer backward
//     }

//     return true;  // If all characters match, it's a palindrome
// }



int left = 0, right = s.size() - 1;

    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) left++;
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) right--;

        // Compare characters (ignoring case)
        if (tolower(s[left]) != tolower(s[right])) return false;

        left++;
        right--;
    }
    return true;
}
};