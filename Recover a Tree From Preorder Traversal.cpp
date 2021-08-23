/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode *>st;
        int i=0;
        while(i < traversal.length()) {
            int level=0;
            while(i<traversal.length() && traversal[i]=='-') {
                level++;
                i++;
            }
            if(i == traversal.length()) {
                break;
            }
            int start = i;
            while(i<traversal.length() && traversal[i]!='-') {
                i++;
            }
            int x = stoi(traversal.substr(start, i-start));
            TreeNode *tmp = new TreeNode(x);
            if(st.empty()) {
                st.push(tmp);
                continue;
            }
            while(st.size() > level) {
                st.pop();
            }
            if(st.top()->left) {
                st.top()->right = tmp;
            } else {
                st.top()->left = tmp;
            }
            st.push(tmp);
        }
        while(st.size()!=1) {
            st.pop();
        }
        return st.top();
    }
};