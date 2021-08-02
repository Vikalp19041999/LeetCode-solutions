class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        int ans = n;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
        }
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) {
                dp[i-1][i]=1;
                ans++;
            }
        }
        for(int size=3; size<=n; size++) {
            for(int j=0; j<n-size+1; j++) {
                if(s[j]==s[j+size-1] && dp[j+1][j+size-2]==1) {
                    dp[j][j+size-1] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};