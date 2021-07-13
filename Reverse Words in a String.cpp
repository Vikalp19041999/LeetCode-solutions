class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string res;
        while(i < s.length()) {
            while(i<s.length() && s[i] == ' ') {
                i++;
            }
            if(i >= s.length()) {
                break;
            }
            int j = i + 1;
            while(j<s.length() && s[j] != ' ') {
                j++;
            }
            if(res.length() == 0) {
                res = s.substr(i, j-i);
            } else {
                res = s.substr(i, j-i) + " " + res;
            }
            i = j + 1;
        }
        return res;
    }
};