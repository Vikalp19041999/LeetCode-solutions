class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res = board;
		for(int i=0; i<board.size(); i++){
			for(int j=0; j<board[i].size(); j++){
				int c1 = 0;
				if((i-1)>=0 && (j-1)>=0){
					if(board[i-1][j-1] == 1) {
                        c1++;
                    }
				}
				if((i-1)>=0 && j>=0){
					if(board[i-1][j] == 1) {
                        c1++;
                    }
				} 
				if((i-1)>=0 && (j+1)<board[i].size()){
					if(board[i-1][j+1] == 1) {
                        c1++;
                    }
				}
				if((i>=0) && (j-1)>=0){
					if(board[i][j-1] == 1) {
                        c1++;
                    }
				}
				if(i>=0 && (j+1)<board[i].size()){
					if(board[i][j+1] == 1) {
                        c1++;
                    }
				}
				if((i+1)<board.size() && (j-1)>=0){
					if(board[i+1][j-1] == 1) {
                        c1++;
                    }
				}
				if((i+1)<board.size() && j>=0){
					if(board[i+1][j] == 1) {
                        c1++;
                    }
				} 
				if((i+1)<board.size() && (j+1)<board[i].size()){
					if(board[i+1][j+1] == 1) {
                        c1++;
                    }
				}
				int val = board[i][j];
				if(val == 0){
					if(c1 == 3) {
                        res[i][j] = 1;
                    } else{
                        res[i][j] = 0;
                    }
				} else{
					if((c1<2) || (c1>3)) {
                        res[i][j] = 0;
                    } else {
                        res[i][j] = 1;
                    }
				}     
			}
		}
		board = res;
    }
};