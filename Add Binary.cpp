class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        int s = 0;
        while (i>=0 || j>=0 || s==1) {
            s += ((i >= 0)? a[i] - '0': 0);
            s += ((j >= 0)? b[j] - '0': 0);
            result = char(s % 2 + '0') + result;
            s /= 2;
            i--;
            j--;
        }
    return result;
    }
};