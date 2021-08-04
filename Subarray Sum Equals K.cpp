class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> sub = {{0, 1}};
        int sum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            sum = sum + nums[i];
            res = res + sub[sum - k];
            sub[sum]++;
        }
        return res;
    }
};