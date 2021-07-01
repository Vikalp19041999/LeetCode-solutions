class Solution {
public:
    vector<vector<int>> result;
    void generate(vector<int>& nums, int i, vector<int>temp) {
        if(i == nums.size()) {
            result.push_back(temp);
            return;
        }
        generate(nums, i+1, temp);
        temp.push_back(nums[i]);
        generate(nums, i+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generate(nums, 0, temp);
        return result; 
    }
};