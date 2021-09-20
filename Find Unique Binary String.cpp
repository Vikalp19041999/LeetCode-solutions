class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        set<string>st(nums.begin(),nums.end());
        for(long long start=0; start<17; start++) {
            string temp = convert(start,n);
            if(st.find(temp)==st.end()) {
                return temp;
            }
        }
        return "";
    }
    
    string convert(long long int n,long long int len) {
        string ans = "";
        while(n) {
            int var = n%2;
            if(var) {
                ans += '1';
            } else {
                ans += '0';
            }
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        int remain = len-ans.size();
        string temp(remain,'0');
        return temp+ans;
    }
};