class Solution {
public:
    int minTimeToType(string word) {
        int t = word.size(); 
        char l = 'a';
        for(char i: word) {
            t += min(abs(i-l), 26 - abs(l-i));
            l = i;
        }
        return t;
    }
};