class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1; i<=n ;i++) {
            for(int j=i; j<=n; j++) {
                int x = (i*i) + (j*j);
                int y = sqrt(x);
                if(y*y == x && y<=n) {
                    ans++;
                }
            }
        }
        return ans*2;
    }
};