class Solution {
public:
    void mark_island(vector<vector<char>>& grid, int i, int j, int rows, int col) {
        if(i<0 || j<0 || i>=rows || j>=col || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        mark_island(grid, i+1, j, rows, col);
        mark_island(grid, i, j+1, rows, col);
        mark_island(grid, i-1, j, rows, col);
        mark_island(grid, i, j-1, rows, col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int ans = 0;
        if(rows == 0) {
            return 0;
        }
        for(int i=0; i<rows; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    mark_island(grid, i, j, rows, col);
                    ans++;
                }
            }
        }
        return ans;
    }
};