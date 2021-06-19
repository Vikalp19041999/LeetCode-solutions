class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        int prod = nums[len - 1];
        if(len == 0) {
            return res;
        }
        res[0] = 1;
        for(int i=1; i<len; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        for(int i = --len-1; i>=0; i--) {
            res[i] = res[i] * prod;
            prod = prod * nums[i];
        }
        return res;
    }
};