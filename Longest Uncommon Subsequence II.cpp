class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,set<int>> mp;
        for(int ind=0; ind<n; ind++){
            string curr = strs[ind];
            int n2 = curr.size();
            for(int i=0; i<(1<<n2); i++){
                string now = "";
                for(int j=0; j<n2; j++){
                    if(i & (1<<j)){
                        now+=curr[j];
                    }
                }
                mp[now].insert(ind);
            }
        }
        int res = -1;
        for(auto it : mp){
            if((int)it.second.size() == 1){
                res = max(res,(int)it.first.size());              
            }
        }
        return res;
    }
};