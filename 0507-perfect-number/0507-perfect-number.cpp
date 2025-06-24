class Solution {
public:
    bool checkPerfectNumber(int num) {
       
        if (num <= 1) return false;
    int sum = 1;
    
    // Loop till sqrt(n)
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) sum += num / i;  // Add the pair divisor
        }
    }

    return sum == num;
    }
};