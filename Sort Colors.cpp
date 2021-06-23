class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0; 
        int right = nums.size()-1;
        int curr = 0;
        while(curr <= right) {
            if(nums[curr] == 0) {
                swap(nums[left], nums[curr]);
                left++;
                curr++;
            } else if(nums[curr] == 1) {
                curr++;
            } else {
                swap(nums[right], nums[curr]);
                right--;
            }
        }
    }
};