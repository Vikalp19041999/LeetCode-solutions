class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
		for(auto num: nums) {
            while(num > 0 && num <= len && nums[num - 1] != num) {
                swap(num, nums[num - 1]);
            }
        }
		for(int i = 0; i < len; ++ i) {
            if(nums[i]!=i + 1) {
                return i+1;
            }
        }
		return len+1;
    }
};