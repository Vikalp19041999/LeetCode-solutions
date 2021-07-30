class Solution {
public:
    bool isMatch(string s, string p) {
       int len1 = s.length();
       int len2 = p.length();
       bool dp[len1+2][len2+2];
       dp[0][0] = true;
       for(int i=1; i<len1+1; i++) {
           dp[i][0] = false;
       }
       for(int i=1; i<len2+1; i++) {
           if(p[i-1] == '*') {
               dp[0][i] = dp[0][i-2];
           } else {
               dp[0][i] = false;
           }
       }
       for(int i=1; i<len1+1; i++) {
           for(int j=1; j<len2+1; j++) {
               if(s[i-1] == p[j-1] || p[j-1] == '.') {
                   dp[i][j] = dp[i-1][j-1];
               } else if(p[j-1] == '*') {
                   if(dp[i][j-2]) {
                       dp[i][j] = true;
                   } else if(p[j-2] == s[i-1] || p[j-2] == '.') {
                       dp[i][j] = dp[i-1][j];
                   } else {
                       dp[i][j] = false;
                   }
               } else {
                   dp[i][j] = false;
               }
           }
       }
       return dp[len1][len2]; 
    }
};