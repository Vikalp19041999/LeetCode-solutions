class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        vector<vector<int>> ans(N,vector<int> (M));
        queue<pair<int,int>> q;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int mindist=0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                ans[x][y] = mindist;
                if(x>0 && mat[x-1][y] == 1) {
                    q.push({x-1,y});
                    mat[x-1][y]=0;
                }
                if(y>0 && mat[x][y-1] == 1) {
				    mat[x][y-1] = 0;
				    q.push({x,y-1});
			    }
			    if(x<N-1 && mat[x+1][y] == 1) {
				    mat[x+1][y] = 0;
				    q.push({x+1,y});
			    }
			    if(y<M-1 && mat[x][y+1] == 1) {
				    mat[x][y+1] = 0;
				    q.push({x,y+1});
			    }
            }
            mindist++;
        }
        return ans;   
    }
};