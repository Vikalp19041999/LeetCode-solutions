class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == 'O') {
            grid[i][j] = '1';
            if(i+1 < grid.size()) {
                dfs(grid, i+1, j);
            }
            if(i > 1) {
                dfs(grid, i-1, j);
            }
            if(j+1 < grid[i].size()) {
                dfs(grid, i, j+1);
            }
            if(j > 1) {
                dfs(grid, i, j-1);
            }
        }
    }
    
    void solve(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return;
        }
        int row = grid.size(); 
        int col = grid[0].size();
        for(int i=0; i<row; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, col-1);
        }
        for(int j=1; j<col-1; j++){
            dfs(grid, 0, j);
            dfs(grid, row-1, j);
        }
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                } else if(grid[i][j] == '1') {
                    grid[i][j] = 'O';
                }
            }
        }
    }
};