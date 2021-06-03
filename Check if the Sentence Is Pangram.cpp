class Solution {
public:
    bool checkIfPangram(string sentence) {
        int a[26] = { 0 }, i;
        for(i=0; i<sentence.length(); i++) {
            a[sentence[i] - 97]++;
        }
        for(i=0; i<26; i++) {
            if(a[i] == 0) {
                return false;
                break;
            }
        }
        return true;
    }
};