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
    TreeNode* buildBst(TreeNode* &root, int val) {
        if(root == NULL) {
            return root = new TreeNode(val);
        }
        if(root->val > val) {
            buildBst(root->left, val);
        } else {
            buildBst(root->right, val);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i=0; i<preorder.size(); i++) {
            buildBst(root, preorder[i]);
        }
        return root;
    }
};