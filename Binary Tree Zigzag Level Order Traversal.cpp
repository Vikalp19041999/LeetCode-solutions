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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        stack<TreeNode*> ls, rs;
        int lev = 1;
        if(root == NULL) {
            return ans;
        }
        ls.push(root);
        while(!ls.empty() || !rs.empty()) {
            if(lev % 2 != 0) {
                while(!ls.empty()){
                    if(ls.top()->left != NULL) {
                        rs.push(ls.top()->left);
                    } 
                    if(ls.top()->right != NULL) {
                        rs.push(ls.top()->right);
                    }
                    level.push_back(ls.top()->val);
                    ls.pop();
                }
                ans.push_back(level);
                level.clear();
            } else {
                while(!rs.empty()){
                    if(rs.top()->right != NULL) {
                        ls.push(rs.top()->right);
                    } 
                    if(rs.top()->left != NULL) {
                        ls.push(rs.top()->left);
                    }
                    level.push_back(rs.top()->val);
                    rs.pop();
                }
                ans.push_back(level);
                level.clear();
            }
            lev++;
        }
        return ans;
    }
};