class Solution {
public:
    string largestOddNumber(string num) {
        int pos = num.size() - 1;
        while(pos >= 0) {
            if((num[pos] - '0')% 2) {
                break;
            }
            pos--;
        }
        if(pos < 0) {
            return "";
        }
        return num.substr(0, pos + 1);
    }
};
