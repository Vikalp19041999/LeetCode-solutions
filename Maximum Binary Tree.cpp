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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) {
            return NULL;
        }
        vector<int>::iterator max = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*max);
        vector<int> left(nums.begin(), max);
        vector<int> right(++max, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};