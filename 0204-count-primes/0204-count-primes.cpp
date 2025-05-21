class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n,true);
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime[i]==true){
                count++;
                for(int j=1;j*i<n;j++){
                    isprime[i*j]=false;
                }
            }
        }
        return count;
    }
};