    class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        } 
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size(); i++) {
            int target_3 = target - nums[i];
            for (int j=i+1; j<nums.size(); j++) {
                int target_2 = target_3 - nums[j];
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    if (nums[left]+nums[right] < target_2) {
                        left++;
                    } else if (nums[left]+nums[right] > target_2) {
                        right--;
                    } else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        res.push_back(quadruplet);
                        while (left < right && nums[left] == quadruplet[2]) {
                            left++;
                        } 
                        while (left < right && nums[right] == quadruplet[3]) {
                            right--;
                        }
                    }
                }
                while(j+1<nums.size() && nums[j+1] == nums[j]) {
                    j++;
                }
            }
            while(i+1<nums.size() && nums[i+1] == nums[i]) {
                i++;
            }
        }
        return res;
        }
    };