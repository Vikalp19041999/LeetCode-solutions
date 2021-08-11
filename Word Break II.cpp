class Solution {
public:
    void helper(vector<string>& res, string s, vector<string>& wordDict, int index, int n, string str) {
        if(index == n) {
            str.pop_back();
            res.push_back(str);
        } else {
            for(int i=index; i<n; i++) {
                string temp = s.substr(index, i-index+1);
                if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
                    helper(res, s, wordDict, i+1, n, str + temp+' ');
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        helper(res, s, wordDict, 0, s.size(), "");
        return res;
    }
};