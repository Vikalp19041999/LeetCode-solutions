class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length() == 0 || s.length() < k) {
            return 0;
        }
        if(k <= 1) {
            return s.length();
        }
        int left = 0;
        unordered_map<char, int> store_count;
        for(char c : s) {
            store_count[c]++;
        }
        while(left<s.length() && store_count[s[left]]>=k) {
            left++;
        }
        if(left >= s.length()-1) {
            return left;
        }
        int l1 = longestSubstring(s.substr(0,left), k);
        while(left<s.length() && store_count[s[left]]<k) {
            left++;
        }
        int l2 = (left <= s.length()) ? longestSubstring(s.substr(left), k) : 0;
        return max(l1, l2);
    }
};