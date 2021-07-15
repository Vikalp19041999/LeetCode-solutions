class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned long long> ans(target+1, 0);
        ans[0] = 1;
        for(int i=1; i<=target; i++) {
            for(int x : nums) {
                if(i >= x) {
                    ans[i] = ans[i] + ans[i-x];
                }
            }
        }
        return (int)ans[target];;
    }
};