class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, result = 0;
    
    // Step 1: Ignore leading whitespaces
    while (i < s.length() && s[i] == ' ') {
        i++;
    }

    // Step 2: Check for optional sign (+ or -)
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;  // Set sign accordingly
        i++;  // Move to the next character
    }

    // Step 3: Convert digits to integer while handling overflow
    while (i < s.length() && isdigit(s[i])) {
        int digit = s[i] - '0';  // Convert character to digit

        // Overflow check before adding digit
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;  // Clamp to 32-bit integer range
        }

        result = result * 10 + digit;  // Append digit to result
        i++;  // Move to next character
    }

    return result * sign;  // Apply sign and return final result
}
    
};