class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> result = cost;
        for (int i = 2; i < n; i++) {
            result[i] += min(result[i-2], result[i-1]);
        }
        return min(result[n-1], result[n-2]);
    }
};