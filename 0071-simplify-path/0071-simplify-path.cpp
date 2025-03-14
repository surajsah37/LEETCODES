class Solution {
public:
    string simplifyPath(string path) {
         stack<string> st;  // Stack to store valid directory names
    stringstream ss(path); // String stream to split by '/'
    string dir; // Temporary string to store each directory name

    // Step 1: Process each directory or file name
    while (getline(ss, dir, '/')) {
        if (dir == "..") { 
            if (!st.empty()) st.pop(); // Go one directory back (pop from stack)
        } 
        else if (!dir.empty() && dir != ".") { 
            st.push(dir); // Valid directory name, push it to the stack
        }
    }

    // Step 2: Construct the canonical path
    string result;
    while (!st.empty()) {
        result = "/" + st.top() + result; // Build path from stack
        st.pop();
    }

    // Step 3: Handle edge case where result is empty (return root "/")
    return result.empty() ? "/" : result;
}
};