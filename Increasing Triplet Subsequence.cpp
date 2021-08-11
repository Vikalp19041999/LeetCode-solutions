class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX;
        int j = INT_MAX;
        for(int in=0; in<nums.size(); in++) {
            if(nums[in] <= i) {
                i = nums[in];
            } else if(nums[in] <= j) {
                j = nums[in];
            } else {
                return true;
            }
        }
        return false;
    }
};