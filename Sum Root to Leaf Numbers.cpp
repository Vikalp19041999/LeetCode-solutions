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
    void dfs(TreeNode* root, int &sum, int current){
        if(root == NULL) {
            return;
        }
        current = (current * 10) + root->val;
        if(!root->right && !root->left) {
            sum = sum + current;
        }
        if(root->left) {
            dfs(root->left, sum, current);
        }
        if(root->right) {
            dfs(root->right, sum, current);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }
};