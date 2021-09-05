class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        for(auto &x : row ) {
            x /= 2 ;
        } 
        int count = 0 ; 
        for(int i=0; i<row.size(); i+=2 ) {
            if(row[i+1] == row[i]) {
                 continue;
             } else {
                 count++;
             }
             for(int j=i+2; j<row.size(); j++) {
                 if(row[i] == row[j]) {
                     swap(row[i+1], row[j] );
                 }
             }
        }
        return count;
    }
};