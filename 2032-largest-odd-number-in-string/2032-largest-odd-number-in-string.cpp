class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;--i){
             // Check if the current digit is odd (1, 3, 5, 7, 9)
            if((num[i]-'0')%2==1)
            {   
                 // If it's odd, return the substring from beginning to this position (inclusive)
                return num.substr(0,i+1);
            }
        }
          return "";
    }
  
};