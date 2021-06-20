class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> res(256, -1);
        int left = 0; 
        int right = 0;
        int length = 0;
        while(right < s.size()) {
            if(res[s[right]] != -1) {
                left = max(res[s[right]]+1, left);
            }
            res[s[right]] = right;
            length = max(length, right-left+1);
            right++;
        }
        return length;
    }
};