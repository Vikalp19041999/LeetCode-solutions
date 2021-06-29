class Solution {
public:
    int findParent(int node, vector<int> &parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }
    
    void findUnion(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findParent(u, parent);
        v = findParent(v, parent);
        if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int>rank(n,0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isConnected[i][j]) {
                    findUnion(i, j, parent, rank);
                }
            }
        }
        map<int,int>mp;
        int count =0;
        for(int i=0; i<n; i++) {
        for(int j=i;j<n;j++) {
            if(isConnected[i][j]) {
                if(findParent(i,parent) == findParent(j,parent) && mp.find(findParent(i,parent)) == mp.end()) {
                    count++;
                    mp[findParent(i,parent)] = 1;
                }
            }
        }   
    }
    return count;
    }
};