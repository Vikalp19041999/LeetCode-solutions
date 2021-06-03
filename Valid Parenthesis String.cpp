class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stack1, stack2;
        int len = s.length();
        for(int i=0;s[i]!='\0';++i)
        {
            if(s[i]=='(') {
                stack1.push(i);
            } else if(s[i]=='*') {
                stack2.push(i);
            } else {
                if(!stack1.empty()) {
                    stack1.pop();
                } else if(!stack2.empty()) {
                    stack2.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        while(!stack1.empty())
        {
            if(stack2.empty()) {
                return false;
            } else if(stack1.top() < stack2.top()) {
                stack1.pop();
                stack2.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};