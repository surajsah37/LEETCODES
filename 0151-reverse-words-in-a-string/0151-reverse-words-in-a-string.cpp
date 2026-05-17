class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string words = "";
        string result = "";

        // Traverse string
        for(int i = 0; i < s.length(); i++) {

            if(s[i] != ' ') {
                words += s[i];
            }
            else {

                // Push complete word
                if(!words.empty()) {
                    st.push(words);
                    words = "";
                }
            }
        }

        // Push last word
        if(!words.empty()) {
            st.push(words);
        }

        // Reverse words using stack
        while(!st.empty()) {

            result += st.top();
            st.pop();

            if(!st.empty()) {
                result += " ";
            }
        }

        return result;
    }
};