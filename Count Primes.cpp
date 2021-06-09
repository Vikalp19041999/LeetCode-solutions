class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) {
            return 0;
        }
        vector <int> prime(n+1, 1);
        prime[0] = prime[1] = 0;
        for(int i=2; i*i<=n; i++) {
            if(prime[i] == 1) {
                for(int j=2; i*j<=n; j++) {
                    prime[i*j] = 0;
                }
            }
        }
        for(int i=1; i<=n; i++) {
            prime[i] += prime[i-1];
        }
        return prime[n-1];
    }
};