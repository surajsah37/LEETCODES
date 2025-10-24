class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string words, result;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                words += s[i];
            } 
            else if (!words.empty()) {
                st.push(words);
                words = "";
            }
        }

        // ✅ Push the last word (if string doesn't end with space)
        if (!words.empty()) st.push(words);

        // ✅ Build result by popping from stack (after reading full string)
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) result += " ";
        }

        return result;
    }
};
