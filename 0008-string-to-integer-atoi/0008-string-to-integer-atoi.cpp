class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long result = 0;         // Use long to handle overflow during calculation
        int sign = 1;            // Default sign is positive

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Handle optional '+' or '-' sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits and convert to number
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; // Convert char to int

            // 4. Check for overflow/underflow before adding the digit
            if (result > (INT_MAX - digit) / 10) {
                // If result is going to overflow, clamp the value
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // 5. Apply the sign and return the final integer
        return static_cast<int>(result * sign);
    }
};
