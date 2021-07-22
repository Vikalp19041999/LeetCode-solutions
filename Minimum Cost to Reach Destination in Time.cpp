#define pr pair<int, pair<int, int>>
#define ll long long int
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<pair<int, int>> adj[n];
        for(vector<int> e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({passingFees[0], {0, 0}});
        unordered_map<int, int> vis;
        while(!pq.empty()) {
            pr crr = pq.top(); pq.pop();
            int curr = crr.second.first; 
            int time = crr.second.second; 
            int cost = crr.first;
            if(curr == n-1) {
                return cost;
            }
            vis[curr] = time;
            for(pair<int, int> p : adj[curr]) {
                int ad = p.first;
                int ctime = p.second;
                int ttime = time + ctime;
                if(vis.find(ad) != vis.end() && vis[ad] <= ttime) {
                    continue;
                }
                vis[ad] = ttime;
                if(ttime <= maxTime) {
                    pq.push({cost + passingFees[ad], {ad, ttime}});
                }
            }
        }
        return -1;
    }
};