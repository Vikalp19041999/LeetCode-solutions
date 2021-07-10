class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int source, int row, int col, int newColor) {
        if(sr<0 || sc<0 || sr>=row || sc>=col) {
            return;
        } else if(image[sr][sc] != source) {
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr+1, sc, source, row, col, newColor);
        dfs(image, sr-1, sc, source, row, col, newColor);
        dfs(image, sr, sc+1, source, row, col, newColor);
        dfs(image, sr, sc-1, source, row, col, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        int source = image[sr][sc];
        if(source == newColor) {
            return image;
        }
        dfs(image, sr, sc, source, row, col, newColor);
        return image;
    }
};