class Solution {
public:
    unordered_map<string, int> mp;
    long long ways(vector<int>& nums, int n, int target, int sum, int pos) {
        if(n == pos) {
            if(sum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        string key = to_string(pos) + "*" + to_string(sum);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }
        return mp[key] = ways(nums, n, target, sum+nums[pos], pos+1) + ways(nums, n, target, sum-nums[pos], pos+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        return ways(nums, n, target, nums[0], 1) + ways(nums, n, target, -nums[0], 1);
    }
};