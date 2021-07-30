class Solution {
public:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int x) {
        if(x == word.length()) {
            return true;
        }
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || board[i][j]!=word[x]) {
            return false;
        }
        char c = board[i][j];
        board[i][j] = '*';
        if(dfs(board, word, i+1, j, x+1) ||
        dfs(board, word, i-1, j, x+1) ||
        dfs(board, word, i, j+1, x+1) ||
        dfs(board, word, i, j-1, x+1)) {
            return true;
        }
        board[i][j]=c;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};