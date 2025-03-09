class Solution {
public:
    string addStrings(string num1, string num2) {
       
    int i = num1.size() - 1;  // Pointer to the last digit of num1
    int j = num2.size() - 1;  // Pointer to the last digit of num2
    int carry = 0;            // Variable to store carry during addition
    string result = "";       // String to store the final result

    // Loop until all digits of both numbers are processed or there is a carry
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;  // Start with carry from previous addition

        // Add the digit from num1 if available
        if (i >= 0) sum += num1[i--] - '0';

        // Add the digit from num2 if available
        if (j >= 0) sum += num2[j--] - '0';

        carry = sum / 10;  // Compute carry for next iteration
        result.push_back((sum % 10) + '0');  // Store the last digit of sum in result
    }

    // Since we computed the result in reverse order, we need to reverse it
    reverse(result.begin(), result.end());
    return result;
}
};