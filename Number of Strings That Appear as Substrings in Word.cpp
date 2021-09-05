class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string> s;
        int total = 0;
        for(int i=0; i<=word.size(); i++) {
            for(int j=word.size()-i; j>=1; j--) {
                s.insert(word.substr(i, j));
            }
        }
        for(auto i : patterns) {
            if(s.count(i) == 0) {
                continue;
            } else {
                total++;
            }
        }
        return total;
    }
};