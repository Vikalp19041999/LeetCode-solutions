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
    unordered_map <int, int> M;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            M[inorder[i]] = i;
        }
        return built(preorder, inorder, 0, inorder.size()-1, 0);
    }
    
public: 
    TreeNode* built(vector<int>& preorder, vector<int>& inorder, int front, int back, int preIndex) {
        if(front > back) {
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[preIndex]);
        int index = M[preorder[preIndex]];
        root->left = built(preorder, inorder, front, index-1, preIndex+1);
        root->right= built(preorder, inorder, index+1, back, preIndex+index-front+1);
        return root;
    }
};