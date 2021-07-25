class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> res(n, vector<int>(m, -1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(isWater[i][j]) {
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            auto a = q.front();
            q.pop();
            int x = a.first;
            int y = a.second;
            int v = res[x][y];
            vector<int> temp = {-1, 0, 1, 0, -1};
            for(int i=0; i<temp.size()-1; i++) {
                if(x+temp[i]>=0 && x+temp[i]<n && y+temp[i+1]<m && y+temp[i+1]>=0) {
                    if(res[x+temp[i]][y+temp[i+1]] == -1) {
                        res[x+temp[i]][y+temp[i+1]] = v+1;
                        q.push({x+temp[i], y+temp[i+1]});
                    }
                }
            }
        }
        return res;
    }
};