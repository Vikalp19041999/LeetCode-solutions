/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        distanceK(root, target, K, res);
        return res;
    }

    int distanceK(TreeNode* node, TreeNode* target, int K, vector<int>& res) {
        if (node == NULL) {
            return 0;
        }
        if (node == target) {
            traverseSubtree(node, K, res);
            return 1;
        }
        int dL = distanceK(node->left, target, K, res);
        if (dL != 0) {
            if (dL == K) {
                res.push_back(node->val);
            } else if (dL < K) {
                traverseSubtree(node->right, K-dL-1, res);
            }
            return dL + 1;
        }   
        int dR = distanceK(node->right, target, K, res);
        if (dR != 0) {
            if (dR == K) {
                res.push_back(node->val);
            } else if (dR < K) {
                traverseSubtree(node->left, K-dR-1, res);
            }
            return dR + 1;
        }
        return 0;
    }

    void traverseSubtree(TreeNode* node, int K, vector<int>& res) {
        if (node == NULL) {
            return;
        }
        if (K == 0) {
            res.push_back(node->val);
            return;
        }
		traverseSubtree(node->left, K-1, res);
        traverseSubtree(node->right, K-1, res);
    }
};