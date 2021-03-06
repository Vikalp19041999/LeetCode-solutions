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
    vector<vector<int>> paths;
    void findPaths(TreeNode* node, int target, int curr, vector<int> &path) {
        if (node == NULL) {
            return;
        }
        curr = curr + node->val;
        path.push_back(node->val);
        if (curr == target && node->left == node->right) {
            paths.push_back(path);
        }
        findPaths(node->left, target, curr, path);
        findPaths(node->right, target, curr, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        findPaths(root, targetSum, 0, path);
        return paths;
    }
};