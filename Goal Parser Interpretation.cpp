class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i=0; i<command.length(); i++) {
            if(command[i] == 'G') {
                res = res + command[i];
            } else if(command[i] == '(') {
                if(command[i+1]=='a' && command[i+2]=='l' && command[i+3]==')') {
                    res = res + 'a' + 'l';
                } else if(command[i+1] == ')') {
                    res = res + 'o';
                }
            }
        }
        return res;
    }
};