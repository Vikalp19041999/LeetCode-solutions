class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long count = 0;
        long long mini = INT_MAX; 
        long long sum_abs = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] < 0) {
                    count++;
                }
                mini = min(mini, (long long)abs(matrix[i][j]));
                sum_abs += abs(matrix[i][j]);
            }
        }
        sum_abs -= count % 2 ? 2 * mini : 0;
        return sum_abs;
    }
};