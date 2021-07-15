class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m, n, i, j;
        m = text1.size();
        n = text2.size();
        int L[m+1][n+1];
        for(i=0; i<m+1; i++) {
            for(j=0; j<n+1; j++) {
                if(i==0 || j==0) {
                    L[i][j] = 0;
                } else if(text1[i-1] == text2[j-1]) {
                    L[i][j] = L[i-1][j-1] + 1;
                } else {
                    L[i][j] = max(L[i-1][j], L[i][j-1]);
                }
            }
        }
        return L[m][n];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(t, s);
    }
};