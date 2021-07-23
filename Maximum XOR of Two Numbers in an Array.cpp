class TrieNode{
  public:
    TrieNode *child[2];
    TrieNode() {
        for(int i=0; i<2; i++) {
            child[i]=NULL;
        }
    }
};

class Solution {
public:
    void insert(int x, TrieNode *head) {
        for(int i=31; i>=0; i--) {
            int val=(x>>i) & 1;
            if(head->child[val] == NULL) {
                head->child[val] = new TrieNode();
            }
            head=head->child[val];
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode * root = new TrieNode();
        for(int i=0; i<nums.size(); i++){
            insert(nums[i],root);
        }
        int maxx=0;
        for(int i=0; i<nums.size(); i++) {
            int cur=0;
            TrieNode *head=root;
            long long p = (1L<<31);
            for(int j=31; j>=0; j--) {
                int val=(nums[i]>>j) & 1;
                if(head->child[!val] != NULL) {
                    head = head->child[!val];
                    cur+= p;
                } else {
                    head = head->child[val];
                }
                p = p>>1;
            }
            maxx = max(maxx, cur);
        }
        return maxx;
    }
};