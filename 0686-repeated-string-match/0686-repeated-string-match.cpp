class Solution {
public:
    int repeatedStringMatch(string a, string b) {
       string repeated="";
       int count=0;
       while(repeated.length()<b.length()+a.length()){
        repeated+=a;
        count++;
        if(repeated.find(b)!=string::npos){
            return count;
        }
       } 
       return -1;
    }
};