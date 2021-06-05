class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int sum = 0 - nums[i];
            int right = nums.size()-1;
            int left = i+1;
            while(right>left){
                if((nums[right]+nums[left]) > sum)
                    right--;
                else if((nums[right]+nums[left]) < sum)
                    left++;
                else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while((right > left) && nums[right] == nums[right+1]) {
                        right--;
                    };
                    while((right > left) && nums[left]==nums[left-1]) {
                        left++;
                    };
                }    
            }
        }
        return res;
    }
};