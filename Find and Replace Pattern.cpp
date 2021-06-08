class Solution {
public:
    bool matches(string word, string pattern) {
        vector <int> fw(26, -1), bw(26, -1);
        for(int i=0; i<word.size(); i++) {
            char c = word[i] - 'a', d = pattern[i] - 'a';
            if(fw[c] != -1 && fw[c] != d) {
                return false;
            }
            if(bw[d] != -1 && bw[d] != c) {
                return false;
            }
            fw[c] = d;
            bw[d] = c;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> ans = {};
        for(auto word: words) {
            if(matches(word, pattern)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};