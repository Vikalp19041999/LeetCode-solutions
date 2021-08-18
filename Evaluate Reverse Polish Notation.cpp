class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int i = 0;
        while(i<tokens.size()) {
           if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {  
              int a = s.top();
              s.pop();
              int b = s.top();
              s.pop();
              if(tokens[i]=="+") {
                  s.push(a+b);
              } else if(tokens[i]=="-") {
                  s.push(b-a);
              } else if(tokens[i]=="*") {
                  s.push(a*b);
              } else {
                  s.push(b/a);
              }
           } else {
              int c=stoi(tokens[i]);
              s.push(c);
          }
          i++;
       }
       if(!s.empty()) {
           return s.top();
       }
       return 0;
    }
};