class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) {
            map[c]++;
        }
        int counter = t.size();
        int begin = 0;
        int end = 0; 
        int d = INT_MAX;
        int head=0;
        while(end < s.size()) {
            if(map[s[end++]]-->0) {
                counter--;
            }
            while(counter == 0) {
                if(end-begin < d) {
                    d = end-(head=begin);
                }
                if(map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};

