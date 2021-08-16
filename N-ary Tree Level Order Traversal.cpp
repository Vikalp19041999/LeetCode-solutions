/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        while(q.size()) {
            vector<int> dummy;
            int n = q.size();
            for(int i=0; i<n; i++) {
                auto temp = q.front();
                dummy.push_back(temp->val);
                q.pop();
                auto nums = temp->children;
                for(int j=0; j<nums.size(); j++) {
                    q.push(nums[j]);
                }
                
            }
         res.push_back(dummy);
        }
    return res;
    }
};