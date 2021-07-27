class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int node) {
        path.push_back(node);
        if(node == graph.size()-1) {
            res.push_back(path);
        } else {
            for(int v : graph[node]) {
                dfs(graph, res, path, v);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, path, 0);
        return res;
    }
};