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
    int maxSum(TreeNode* root, int &result) {
        if(root == NULL) {
            return 0;
        }
        int left = maxSum(root->left, result);
        int right = maxSum(root->right, result);
        int straight = max(max(left, right)+root->val, root->val);
        int caseVal = max(straight, left+right+root->val);
        result = max(caseVal, result);
        return straight;
    }
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxSum(root, result);
        return result;
    }
};