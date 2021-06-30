class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int j = 0;
        vector<pair<int, int>> zeros(len);
        for(string str : strs) {
            int i = 0;
            for(char c : str) {
                if(c == '1')
                    i++;
            }
            zeros[j] = {i, str.size() - i};
            j++;
        };
        int dp[n + 1][m + 1][len + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int index = 1; index <= len; index++) {
                    if(i - zeros[index - 1].first >= 0 && j - zeros[index - 1].second >= 0) {
                        dp[i][j][index] = max(dp[i][j][index], dp[i - zeros[index - 1].first][j - zeros[index - 1].second][index - 1] + 1);
                    }
                    dp[i][j][index] = max(dp[i][j][index], dp[i][j][index - 1]);
                }
            }
        }
        
        return dp[n][m][len];
    }
};