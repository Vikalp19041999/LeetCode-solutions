class Solution {
public:
    bool static comparator(string a, string b) {
        if(a+b > b+a) {
            return true;
        } else {
            return false;
        }
    }
    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> arr;
        for(auto i : nums) {
            arr.push_back(to_string(i));
        }
        sort(arr.begin(), arr.end(), comparator);
        for(auto it : arr) {
            res = res + it;
        }
        return res[0] == '0' ? "0" : res;
    }
};