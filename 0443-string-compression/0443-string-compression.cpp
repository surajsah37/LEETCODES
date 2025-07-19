class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();       // Get the length of the input array
        int index = 0;              // This pointer is for writing the compressed characters
        int i = 0;                  // This pointer is for reading through the input array

        while (i < n) {
            char currentChar = chars[i];  // Store the current character
            int count = 0;                // Initialize count of current character

            // Count how many times the currentChar appears consecutively
            while (i < n && chars[i] == currentChar) {
                i++;        // Move read pointer
                count++;    // Increase the count
            }

            // Write the character once in the array at the index position
            chars[index++] = currentChar;

            // If the count is more than 1, write each digit of the count
            if (count > 1) {
                string cntstr = to_string(count);  // Convert count to string

                // Write each digit of the count as a character
                for (char c : cntstr) {
                    chars[index++] = c;  // Store digit character in chars
                }
            }
        }

        // Return the new length of the compressed array
        return index;
    }
};
