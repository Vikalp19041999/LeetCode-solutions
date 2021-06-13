class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index = -1;
        if(nums.size()==1) {
            return 0;
        }
        if(nums.size()==2) {
            if(nums[0] > nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }
        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            if(nums[0] > nums[1]) {
                return 0;
            } else {
                return nums.size() - 1;
            }
        }
        return index;
    }
};