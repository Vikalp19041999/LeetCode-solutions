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
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        int total = 0;
        if(root == NULL) {
            return 0;
        }
        if(umap.count(root)) {
            return umap[root];
        }
        if(root->left) {
            total = total + rob(root->left->left) + rob(root->left->right);
        }
        if(root->right) {
            total = total + rob(root->right->left) + rob(root->right->right);
        }
        return umap[root] = max((root->val+total), (rob(root->left)+rob(root->right)));
    }
};
