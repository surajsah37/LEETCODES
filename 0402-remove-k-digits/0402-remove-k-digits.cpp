class Solution {
public:
    string removeKdigits(string num, int k) {
         vector<char> stack;

        for (char digit : num) {
            // Remove larger digits from stack to make number smaller
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit); // Add current digit
        }

        // Remove remaining digits from end if needed
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        // Build result and remove leading zeros
        string result;
        bool leadingZero = true;
        for (char c : stack) {
            if (leadingZero && c == '0') continue; // skip leading zero
            leadingZero = false;
            result += c;
        }
        return result.empty() ? "0" : result;
    }
};