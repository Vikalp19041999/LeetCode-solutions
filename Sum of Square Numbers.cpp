class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<long long int, long long int> s;
        for(long long int i=0; i*i<=c; i++) {
            s[i*i] = 1;
            if (s.find(c-i*i) != s.end()) {
                return true;
            }
        }
        return false;
    }
};