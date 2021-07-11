class Solution {
public:
    vector<vector<int>> result;
    void combinationCheck(vector<int> &temp, int k, int n, int start) {
        if(k == temp.size()) {
            if(n == 0) {
                result.push_back(temp);
            }
            return;
        }
        for(int i=start; i<=9; i++) {
            temp.push_back(i);
            combinationCheck(temp, k, n-i, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        combinationCheck(temp, k, n, 1);
        return result;
    }
};