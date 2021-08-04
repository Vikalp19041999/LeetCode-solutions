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
    int path(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        if(root->val == targetSum) {
            res++;
        }
        res = res + path(root->left, targetSum - root->val);
        res = res + path(root->right, targetSum - root->val);
        return res;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return 0;
        }
        return pathSum(root->left, targetSum) + path(root, targetSum) + pathSum(root->right, targetSum);
    }
};
