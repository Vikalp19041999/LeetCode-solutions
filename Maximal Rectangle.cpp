class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        int mx = 0;
        vector<vector<int>> mat(row+1, vector<int> (col));
        for(int i=1; i<=row; i++) {
            for(int j=0; j<col; j++) {
                mat[i][j] = matrix[i-1][j] == '1' ? 1 : 0;
            }
        }
        vector<vector<int>> dp(row+1, vector<int> (col));
        for(int i=1; i<=row; i++) {
            vector<int> left(col);
            stack<int> st;
            int leftBound = -1;
            for(int j=0; j<col; j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] = 1 + mat[i-1][j];
                    while(!st.empty() and mat[i][st.top()] >= mat[i][j]) {
                        st.pop();
                    }
                    int val = leftBound;
                    if(!st.empty()) {
                        val = max(val, st.top());
                    }
                    left[j] = val;
                } else {
                    leftBound = j;
                    left[j] = 0;
                }
                st.push(j);
            }
            while(!st.empty()) {
                st.pop();
            }
            int rightBound = col;
            for(int j=col-1; j>=0; j--) {
                if(mat[i][j] != 0) {
                    while(!st.empty() && mat[i][st.top()] >= mat[i][j]) {
                        st.pop();
                    }
                    int val = rightBound;
                    if(!st.empty()) {
                        val = min(val, st.top());
                    }
                    dp[i][j] = mat[i][j] * ((val-1)-(left[j]+1)+1);
                    mx = max(dp[i][j], mx);
                    st.push(j);
                } else {
                    dp[i][j] = 0;
                    rightBound = j;
                }
            }
        }
        return mx;
    }
};