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
    int inOrder(TreeNode* root) {
        while(root->left!=NULL) {
            root = root->left;
        }
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return root;
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if(root->left == NULL) {
                return root->right;
            } else if(root->right == NULL) {
                return root->left;;
            } else {
                root->val = inOrder(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};