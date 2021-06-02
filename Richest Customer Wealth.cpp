class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum1 = 0;
        for(int i=0; i<accounts.size(); i++) {
            int sum2 = 0;
            for(int j=0; j<accounts[i].size(); j++) {
                sum2 = sum2 + accounts[i][j];
            }
            sum1 = max(sum1, sum2);
        }
        return sum1;
    }
};