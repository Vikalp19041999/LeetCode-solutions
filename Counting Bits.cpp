class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++) {
            int count = 0;
            int m = i;
            while(m) {
                count++;
                m = m & (m-1);
            }
            res.push_back(count);
        }
        return res;
    }
};