class Solution {
public:
    bool kahnAlgorithm(vector<vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans) {
        queue<int> q;
        int count = 0;
        for(int i=0; i<n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                indegree[it] -= 1;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
            ans.push_back(node);
            count++;
        }
        if (count != n) {
            return false;
        }
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int n = prerequisites.size();
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i=0; i<n; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }
        if (kahnAlgorithm(adj, numCourses, indegree, ans)) {
            return ans;
        }
        return {};
    }
};