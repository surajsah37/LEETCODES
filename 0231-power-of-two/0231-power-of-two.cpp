class Solution {
public:
    bool isPowerOfTwo(int n)
    {
    if (n <= 0) return false;       // powers of 2 are positive

    return (n & (n - 1)) == 0;      // only one set bit check

    }
};