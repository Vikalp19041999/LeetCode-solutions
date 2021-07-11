class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        for(int i : nums) {
            one = (one^i) & ~two;
            two = (two^i) & ~one;
        }
        return one;
    }
};