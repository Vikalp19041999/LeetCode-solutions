class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> val(nums.size());
        copy(nums.begin(), nums.end(), val.begin());
        sort(val.begin(), val.end());
        int index = nums.size() - 1;
        for(int i=1; i<nums.size(); i+=2) {
            nums[i] = val[index--];
        }
        for(int i=0; i<nums.size(); i+=2) {
            nums[i] = val[index--];
        }
    }
};