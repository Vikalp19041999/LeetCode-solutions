class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c : s) {
            if(c == '(') {
                st.push(0);
            } else {
                int temp = st.top();
                st.pop();
                int val = 0;
                if(temp > 0) {
                    val = temp * 2;
                } else {
                    val = 1;
                }
                st.top() = st.top() + val;
            }   
        }
        return st.top();
    }
};