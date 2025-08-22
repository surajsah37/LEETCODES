class Solution {
public:
    double myPow(double x, int n) {
     long long N = n; // use long long to handle INT_MIN case
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {   // if N is odd
                result *= x;
            }
            x *= x;             // square the base
            N /= 2;             // halve the exponent
        }
        return result;
    }
};