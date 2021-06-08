class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, n;
        do {
            if(nums[i] > 0) {
                n = nums[i];
                nums[i] = -nums[i];
                i = n;
            } else {
                return i;
                break;
            }
        } while(true);
    }
};