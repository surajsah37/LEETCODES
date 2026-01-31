class Solution 
{
public:
    string reverseWords(string s) 
    {
        stack<string> st;
        string words = "", result = "";

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ')
            {
                words += s[i];
            }
            else if(!words.empty())
            {
                st.push(words);
                words = "";
            }
        }

        if(!words.empty())
        {
            st.push(words);
        }

        while(!st.empty())
        {
            result += st.top();
            st.pop();

            if(!st.empty())
            {
                result += " ";   // ⭐ only fix here
            }
        }

        return result;
    }
};
