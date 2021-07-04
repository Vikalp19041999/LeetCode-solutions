class Solution {
public:
    vector<string> ans;
    void f(string s,int open,int close) {        
        if(open==0 && close==0) {                  
            ans.push_back(s);
            return;
        }
        if(open > 0) {
            f(s+"(",open-1,close);
        }
        if(open<close) {
            f(s+")",open,close-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        ans.clear();
        f("", n, n);
        return ans;
    }
};