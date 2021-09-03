class Solution {
    #define ll long long
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>>vec(n+1);
        for(int i=0; i<roads.size(); i++) {
            vec[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            vec[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        long long INF = 1e15;
        long long MOD = 1e9 + 7;
        vector <long long> dp(n+1, 0);
        vector <long long> dist(n+1, INF);
        priority_queue  <pair <long long, long long>> q;
        dp[0] = 1;
        dist[0] = 0;
        q.push({0, 0});
        while(q.size()){
            long long parCost=-q.top().first;
            long long parNode = q.top().second;
            q.pop();
            if(dist[parNode] < parCost) {
                continue;
            }
            for(auto child: vec[parNode]) {
                long long childNode=child.first;
                long long childCost=child.second;
                if(parCost + childCost == dist[childNode]) {
                    dp[childNode] = (dp[parNode]+dp[childNode]) % MOD;
                }
                if(parCost + childCost < dist[childNode]) {
                    dp[childNode] = dp[parNode]%MOD;
                    dist[childNode] = parCost + childCost;
                    q.push({-dist[childNode], childNode});
                }
            }
        }
        return dp[n-1];
    }
};