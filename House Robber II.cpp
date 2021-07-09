class Solution {
public:
    int solve(vector<int> nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++) {
            dp[i] = max((nums[i] + dp[i-2]), dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        int set1 = solve(vector<int>(nums.begin(), nums.end()-1));
        int set2 = solve(vector<int>(nums.begin()+1, nums.end()));
        return max(set1, set2);
    }
};
