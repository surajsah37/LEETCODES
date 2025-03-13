class Solution {
public:
    string reverseWords(string s) {
         stack<string> st;  // Stack to store words
    string word, result;  // Temporary variables for processing words
    int n = s.length();

    // Traverse the string to extract words
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {  // If the character is not a space
            word += s[i];  // Append the character to the current word
        } 
        else if (!word.empty()) {  // If we encounter a space and there's a word
            st.push(word);  // Push the word to the stack
            word = "";  // Reset the word
        }
    }
    
    // Push the last word if it exists
    if (!word.empty()) {
        st.push(word);
    }

    // Build the reversed string from stack
    while (!st.empty()) {
        result += st.top();  // Get the top word from the stack
        st.pop();  // Remove it from the stack
        if (!st.empty()) {
            result += " ";  // Add space if more words remain
        }
    }

    return result;  // Return the final reversed string

    }
};