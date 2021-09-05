class Solution {
public:
    long long MOD = 1000000007;
    long long expn(long long N, long long K) {
        if(K == 0) {
            return 1;
        }
        if(K == 1) {
            return N % MOD;
        }
        if(K%2 == 0) {
            long long temp = expn(N, K/2);
            return (temp*temp)%MOD;
        } else{
            long long temp = expn(N,K/2);
            temp = (temp*temp)%MOD;
            return (temp*(N%MOD))%MOD;
        }
    }
    int minNonZeroProduct(int p) {
        long long val = pow(2, p);    
        val--; 
        long long K = val/2;
        long long N = val-1;            
        long long ans = expn(N, K);
        return ans*((val)%MOD)%MOD;
    }
};