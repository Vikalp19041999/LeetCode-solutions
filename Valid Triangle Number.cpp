class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1; i>=0; i--) {
            int low = 0; 
            int high = i-1; 
            while (low<high) {
                if(nums[low] + nums[high] > nums[i]) {
                    count += high - low;
                    high--;
                }
                else low++;
            }
        }
        return count;
    }
};