class Solution {
public:
    long long int calc(vector<int>&nums, int i,int chance, vector<vector<long long int>>&dp) {
        if(i == nums.size()) {
            return 0;
        }
        if(dp[i][chance] != -1) {
            return dp[i][chance];
        }
        if(chance == 1) {
            long long int a = nums[i] + calc(nums, i+1, 0, dp);
            long long int b= calc(nums, i+1, chance, dp);
            return dp[i][chance] = max(a, b);
        }
        long long int a = calc(nums, i+1, 1, dp) - nums[i];
        long long int b = calc(nums, i+1, chance, dp);
        return dp[i][chance] = max(a, b);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long int>>dp(nums.size()+2,vector<long long int>(2,-1));
        return calc(nums, 0, 1, dp);
    }
};