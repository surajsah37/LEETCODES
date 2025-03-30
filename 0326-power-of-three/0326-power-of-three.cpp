class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
        if(n<=0)  return false;
        long long x=1;
        while(x<=n){
            if(x==1)   return true;
            x*=3;
        }
        return false;
*/
// The largest power of 3 within the range of int (3^19 = 1162261467)
    return (n > 0 && 1162261467 % n == 0);
    }
};