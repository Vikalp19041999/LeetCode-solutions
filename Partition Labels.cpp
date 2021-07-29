class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> end_index(26, 0);
        vector<int> result;
        int start = 0;
        int end = 0;
        for(int i=0; i<s.length(); i++) {
            end_index[s[i] - 'a'] = i;
        }
        for(int i=0; i<s.length(); i++) {
            end = max(end, end_index[s[i]-'a']);
            if(i == end) {
                result.push_back(i - start + 1);
                start = i+1;
            }
        }
        return result;
    }
};