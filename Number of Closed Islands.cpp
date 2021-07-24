class Solution {
public:
    bool dfs(vector<vector<int>>& board,int x,int y,int rows,int cols,vector<vector<bool> > &visited){
        if(x<0 || y<0 || x>=rows || y>=cols) {
            return false;
        }
        visited[x][y]=true;
        if((x==0 || y==0 || x==rows-1 || y==cols-1) && board[x][y]==0) {
            return false;
        }
        bool retVal=true;
        if(board[x][y]==1) {
            return true;
        }
        if(!visited[x-1][y]) {
            retVal = retVal & dfs(board,x-1,y,rows,cols,visited);
        }
        if(!visited[x][y-1]) {
            retVal = retVal & dfs(board,x,y-1,rows,cols,visited);
        }
        if(!visited[x+1][y]) {
            retVal = retVal & dfs(board,x+1,y,rows,cols,visited);
        }
        if(!visited[x][y+1]) {
            retVal = retVal & dfs(board,x,y+1,rows,cols,visited);
        }
        return retVal;
    }
    int closedIsland(vector<vector<int>>& board) {
        int rows = board.size();
        if(rows == 0) {
            return 0;
        }
        int cols=board[0].size();
        vector<vector<bool>> visited(rows,vector<bool> (cols,false));
        int count = 0;
        for(int i=1; i<rows-1; i++){
            for(int j=1; j<cols-1; j++){
                if(board[i][j]==0 && !visited[i][j] && dfs(board,i,j,rows,cols,visited)) {
                    count++;
                }
            }
        }
        return count;
    }
};