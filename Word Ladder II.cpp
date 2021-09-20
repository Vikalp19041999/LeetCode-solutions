class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> list(wordList.begin() , wordList.end());
        vector < vector<string>> final_ans;
        queue <vector<string>> q;
        q.push({beginWord});
        while(!q.empty()) {
            int sz = q.size();
            bool des_find = false;
            unordered_set <string> seen;   
            while(sz--) {
                auto curr_path = q.front(); q.pop();
                string last_word = curr_path.back();
                for(int i=0; i < last_word.size(); i++) {
                    char ch = last_word[i];
                    for(int j=0; j<26; j++) {
                        last_word[i] = 'a' + j;
                        if(list.find(last_word) != list.end()) {
                            curr_path.push_back(last_word);
                            if(last_word == endWord) {
                                final_ans.push_back(curr_path);
                                des_find = true;
                            } else {
                                q.push(curr_path);
                            }
                            seen.insert(last_word);
                            curr_path.pop_back();
                        }
                    }
                    last_word[i] = ch;
                }
            }
            for(string word : seen) {
                if(list.count(word)) {
                    list.erase(word);
                }
            }
            if(des_find) {
                break;
            }
        }
        return final_ans;
    }
};