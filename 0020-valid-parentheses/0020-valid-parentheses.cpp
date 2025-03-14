class Solution {
public:
    bool isValid(string s) {
         stack<char> st; // Stack to store opening brackets

    // Step 1: Traverse the input string
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c); // Push opening brackets onto the stack
        } else {
            if (st.empty()) return false; // If closing bracket found but stack is empty, it's invalid

            char top = st.top(); // Get the top element from the stack
            st.pop(); // Remove the top element from the stack

            // Step 2: Check for matching pairs
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false; // Mismatch found, return false
            }
        }
    }

    // Step 3: Ensure stack is empty at the end
    return st.empty();
    }
};