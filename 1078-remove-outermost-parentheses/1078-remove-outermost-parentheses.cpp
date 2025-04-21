class Solution {
public:
    string removeOuterParentheses(string s) {
       int count=0;
       string ans;
       for(int i=0;i<s.size();i++){

        if(s[i]==')')  
        count--;

        if(count!=0)
        ans.push_back(s[i]);

        if(s[i]=='(')
        count++;
       }
       return ans;
    }
};



 /*
         int count = 0;   // Tracks the depth of nested parentheses
        string ans;      // Stores the final modified string

        // Iterate through the given string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') count--;  // Decrement count when encountering ')'

            if (count != 0)            // If count is not zero, append to result (to skip outermost parentheses)
                ans.push_back(s[i]);   // Append current character to the result

            if (s[i] == '(') count++;  // Increment count when encountering '('
        }

        return ans;  // Return the modified string without outermost parentheses
    }
    */