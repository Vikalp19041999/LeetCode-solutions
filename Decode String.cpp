class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string ans = "";
        string temp = "";
        string no;
        for(int i=0 ; i<s.length() ;i++){
            if(s[i] == '[') {
                stk.push('[');
            } else if(s[i] == ']') {
                temp = "";
                no = "" ;
                while(stk.top()!='[') {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                reverse(temp.begin(),temp.end());
                while(!stk.empty() && (stk.top() - '0' <= 9 && stk.top()-'0' >= 0 )) {
                    no += stk.top();
                    stk.pop();
                }
                int num = 0;
                int p = 1;
                for(int k=0 ; k<no.length(); k++){
                     int x = no[k] - '0';
                     num += x*p;
                     p = p*10;
                }           
                string ch = temp;
                while(num>1) {
                    temp += ch;
                    num--;
                }
                if(stk.empty()) {
                    ans += temp;
                } else{
                    for(int j=0 ; j<temp.length(); j++){
                        stk.push(temp[j]);
                    }
                }
            } else{
                if(stk.empty() && ((s[i]-'0' < 0) || (s[i]-'0' > 9))){
                    ans += s[i];
                } else{
                    stk.push(s[i]);
                }
            }
        }
        return ans;
    }
};