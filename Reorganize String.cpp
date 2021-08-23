class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for(auto &i : s) {
            m[i] += 1;
        }
        for(auto &ele : m) {
            pq.push(make_pair(ele.second, ele.first));
        }
        string ans = "";
        while (pq.size() > 1) {
            char mostFrequent = pq.top().second;
            pq.pop();
            char nextFrequent = pq.top().second;
            pq.pop();
            ans += mostFrequent;
            ans += nextFrequent;
            if(m[mostFrequent] - 1 > 0) {
                m[mostFrequent] -= 1;
                pq.push(make_pair(m[mostFrequent], mostFrequent));
            }
            if(m[nextFrequent] - 1 > 0) {
                m[nextFrequent] -= 1;
                pq.push(make_pair(m[nextFrequent], nextFrequent));
            }
        }
        if(pq.size()) {
            char lastChar = pq.top().second;
            if (m[lastChar] > 1) {
                return "";
            } else {
                ans += lastChar;
            }
        }
        return ans;
    }
};