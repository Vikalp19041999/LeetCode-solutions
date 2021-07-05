class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        long long int p = pow(2, n);
        for(int i=0; i<p; i++) {
            ans.push_back(i^(i/2));
        }
        return ans;
    }
};