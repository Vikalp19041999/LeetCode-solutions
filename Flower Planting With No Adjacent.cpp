class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(int i=0; i<paths.size(); i++) {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> ans(n, 0);
        vector<bool> flower(5, false);
        ans[0] = 1;
        for(int i=2; i<=n; i++) {
            flower.assign(5, 0);
            for(int j=0;j<adj[i].size();j++) {
                int child = adj[i][j];
                flower[ans[child-1]] = true;
            }
            for(int j=1; j<=4; j++) {
                if(flower[j] == false) {
                    ans[i-1] = j;
                    break;
                }
            }
        }
        return ans;
    }
};