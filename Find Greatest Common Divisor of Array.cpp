class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smaller = *min_element(begin(nums), end(nums));
        int greater = *max_element(begin(nums), end(nums));
        return __gcd(smaller, greater);
    }
};