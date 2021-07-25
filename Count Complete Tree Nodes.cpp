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
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left_level = 1;
        int right_level = 1;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while(l) {
            l = l->left;
            left_level = left_level + 1;
        }
        while(r) {
            r = r->right;
            right_level = right_level + 1;
        }
        if(left_level == right_level) {
            return pow(2, left_level)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};