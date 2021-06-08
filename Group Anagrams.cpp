class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0) {
            return result;
        }
        unordered_map<string, vector<string>> map;
        for(string s : strs){
            string key = s;
            std::sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};