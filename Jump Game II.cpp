class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = -1; 
        int next = 0; 
        int ans = 0;
        for(int i=0; next<nums.size()-1; i++) {
            if (i > curr) {
                ans++; 
                curr = next;
            }
            next = max(next, nums[i] + i);
        }
        return ans;
    }
};