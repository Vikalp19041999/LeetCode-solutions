class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        sort(arr.begin(), arr.end());
        int index = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
        for(int i=0; i<index; i++) {
            if(mp.count(arr[i]*2)) {
                mp[arr[i]*2]--;
                if(mp[arr[i]*2] == 0) {
                    mp.erase(arr[i]*2);
                }
            } else {
                mp[arr[i]]++;
            }
        }
        for(int i=arr.size()-1; i>=index; i--) {
            if(mp.count(arr[i]*2)) {
                mp[arr[i]*2]--;
                if(mp[arr[i]*2] == 0) {
                    mp.erase(arr[i]*2);
                }
            } else {
                mp[arr[i]]++;
            }
        }
        return mp.empty();
    }
};