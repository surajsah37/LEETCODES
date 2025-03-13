class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();  // Get the length of the string
    int length = 0;  // Variable to store the length of the last word
    
    // Start from the end of the string
    int i = n - 1;
    
    // Ignore trailing spaces by moving `i` left until a non-space character is found
    while (i >= 0 && s[i] == ' ') {
        i--; // Move to the previous character
    }
    
    // Count the length of the last word until a space or start of the string is encountered
    while (i >= 0 && s[i] != ' ') {
        length++; // Increment the word length counter
        i--; // Move to the previous character
    }
    
    return length; // Return the length of the last word

    }
};