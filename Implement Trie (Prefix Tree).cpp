class Trie {
    struct TrieNode {
        char val;
        int count;
        int endsHere;
        TrieNode *child[26];
    };
    
    TrieNode* root;
    
    TrieNode* getNode(int index) {
        TrieNode *newNode = new TrieNode();
        newNode->val = 'a' + index;
        newNode->count = 0;
        newNode->endsHere = 0;
        for(int i=0; i<26; i++) {
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = getNode('/' - 'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        int index;
        for(int i=0; word[i]!='\0'; i++) {
            index = word[i] - 'a';
            if(curr->child[index] == NULL) {
                curr->child[index] = getNode(index);
            }
            curr->child[index]->count += 1;
            curr = curr->child[index];
        }
        curr->endsHere += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        int index;
        for(int i=0; word[i]!='\0'; i++) {
            index = word[i] - 'a';
            if(curr->child[index] == NULL) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int index;
        for(int i=0; prefix[i]!='\0'; i++) {
            index = prefix[i] - 'a';
            if(curr->child[index] == NULL) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */