class Solution {
public:
    bool isPowerOfThree(int n) {
    if(n<1)
    return false;
    while(n%3==0)
    n/=3;
    return n==1;
}
};

// The largest power of 3 within the range of int (3^19 = 1162261467)
    //return (n > 0 && 1162261467 % n == 0);