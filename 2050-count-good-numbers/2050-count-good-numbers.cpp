class Solution {
public:
    const long long MOD = 1e9 + 7;

    // fast power function
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {  // if exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // square the base
            exp >>= 1;                  // divide exponent by 2
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // number of even positions
        long long oddCount = n / 2;         // number of odd positions

        long long part1 = modPow(5, evenCount, MOD); // 5 choices for even indices
        long long part2 = modPow(4, oddCount, MOD);  // 4 choices for odd indices

        return (part1 * part2) % MOD;
    }
};
