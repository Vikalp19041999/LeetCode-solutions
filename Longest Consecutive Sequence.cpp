class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int streak = 0;
        if(nums.size() == 0) {
            return 0;
        }
        set<int>hashset;
        for(int num : nums) {
            hashset.insert(num);
        }
        for(int num : nums) {
            if(!hashset.count(num-1)) {
                int current = num;
                int cs = 1;
                while(hashset.count(current + 1)) {
                    current = current + 1;
                    cs = cs + 1;
                }
                streak = max(streak, cs);
            }
        }
        return streak;
    }
};