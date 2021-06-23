class Solution {
public:
    bool checkCycle(int node, vector<vector<int>>& adj, int vis[], int dfsVis[]) {
        vis[node] = 1; 
        dfsVis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checkCycle(it, adj, vis, dfsVis)) {
                    return true;
                }
            } else if(dfsVis[it]) {
                return true; 
            }
        }
        dfsVis[node] = 0; 
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int vis[numCourses], dfsVis[numCourses]; 
	    memset(vis, 0, sizeof vis); 
	    memset(dfsVis, 0, sizeof dfsVis);
        for(int i=0; i<numCourses; i++) {
	        if(!vis[i]) {
	            if(checkCycle(i, adj, vis, dfsVis)) {
	                return false; 
	            }
	        }
	    }
	    return true;
    }
};