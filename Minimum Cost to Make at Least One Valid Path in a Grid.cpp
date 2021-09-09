class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<pair<int,int>,int>> dq;
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        dq.push_back({{0, 0}, 0});
        int row[4] = {0, 0, 1, -1};
        int col[4] = {1, -1, 0, 0};
        while(!dq.empty()) {
            auto it = dq.front();
            dq.pop_front();
            int i = it.first.first;
            int j = it.first.second;
            int wt = it.second;
            int val = grid[i][j];
            vis[i][j] = 1;
            if(i==n-1 && j==m-1) {
                return wt;
            }
            for(int k=0; k<=3; k++){
                int nx = i + row[k];
                int ny = j + col[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]) {
                    continue;
                }
                if(k+1 == val) {
                    dq.push_front({{nx, ny}, wt});
                } else {
                    dq.push_back({{nx, ny}, wt+1});
                }
            }
        }
        return 0;
    }
};