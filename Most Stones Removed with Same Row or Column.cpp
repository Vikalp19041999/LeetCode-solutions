class Solution {
public:
    int findParent(int node, vector<int> &parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }
    
    void findUnion(int u, int v, vector<int> &parent) {
        u = findParent(u, parent);
        v = findParent(v, parent);
        parent[u] = v;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent;
        unordered_map<int, vector<int>> rowmap, colmap;
        unordered_set<int> unique;
        for(int i=0; i<stones.size(); i++) {
            parent.push_back(i);
        }
        for(int i=0; i<stones.size(); i++) {
		    rowmap[stones[i][0]].push_back(i);
		    colmap[stones[i][1]].push_back(i);
	    }
        for(int i=0; i<stones.size(); i++) {
		    for(int j : rowmap[stones[i][0]]) {
                findUnion(i, j, parent);
            }
		    for(int j : colmap[stones[i][1]]) {
                findUnion(i, j, parent);
            }
	    }
        for(int n : parent) {
            unique.insert(findParent(n, parent));
        }
	    return stones.size() - unique.size();
    }
};