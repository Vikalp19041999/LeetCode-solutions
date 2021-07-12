class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v;
        int count = 1;
        int n = arr.size()/2;
        int ans = 0;
        sort(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == arr[i-1]) {
                count++;
            } else {
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        sort(v.begin(), v.end());
        for(int i=v.size()-1; n>0 && i>=0; i--) {
            ans++;
            n = n-v[i];
        }
        return ans;
    }
};