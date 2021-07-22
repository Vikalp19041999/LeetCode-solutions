class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> mp;
        unordered_map<char,int> mp2;
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                if(t[i] != mp[s[i]]){
                    return false;
                }
            } else if(mp2.find(t[i]) != mp2.end()) {
                return false;
            } else {
                mp[s[i]] = t[i];
                mp2[t[i]]+= 1;
            }
        }
        return true;
    }
};