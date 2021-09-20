class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
       long patches = 0; 
       long count = 1;
       int i = 0;
       while(count <= n) {
          if(i<nums.size() && nums[i]<=count) {
              count = count + nums[i++];
          } else {
             count *= 2;
             patches++;
            }
        }
        return patches; 
    }
};