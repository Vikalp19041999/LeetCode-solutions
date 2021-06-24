class Solution {
    unordered_map<int,vector<int>> graph;
    vector<int> color;
public:
    bool dfs(int node){
        for(auto v : graph[node]) {
            if(color[v] == -1) {
                color[v] = 1-color[node];
                if(!dfs(v)) {
                    return false;
                }
            }
            else if(color[v]==color[node]) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        color.resize(n+1, -1);
        for(int i=1; i<=n; i++) {
            if(color[i] == -1) {
                color[i] = 1;
                if(!dfs(i)) {
                    return false;
                }
            }
        }
        return true;
    }
};